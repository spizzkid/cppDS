//
// Created by spizzkid on 6/7/21.
//

#include "myStack.h"
#include <cassert>
#include <iostream>
using namespace std;

myStack::myStack(int size) {
    capacity = size;
    stackArr = new int[size];
    assert(stackArr != NULL);
    numElements = 0;
}


bool myStack::isEmpty() {
    return (numElements == 0);
}

bool myStack::push(int value) {
    if (numElements < capacity)
    {
        stackArr[numElements] = value;
        numElements++;
        return true;
    }
    else
    {
        cout << "Stack Full\n";
        return false;
    }
}

int myStack::pop() {
    if (numElements == 0)
    {
        cout << "Stack Empty\n";
        return -1;
    }
    else
    {
        numElements--;
        return stackArr[numElements];
    }
}


int myStack::getTop() {
    return (numElements == 0 ? -1 : stackArr[numElements - 1]);
}

int myStack::getSize() {
    return numElements;
}

void myStack::showStack() {
    int i = 0;
    while(i < numElements)
    {
        cout << "\t" << stackArr[numElements - 1 - i];
        i++;
    }
    cout << '\n';

}

myStack sortStack(myStack stack, int size)
{
    myStack tempStack(size);

    while(!stack.isEmpty())
    {
        int val = stack.pop();

        if (val >= tempStack.getTop())
        {
            tempStack.push(val);
        }
        else
        {
            while (!tempStack.isEmpty())
            {
                stack.push(tempStack.pop());
            }
            tempStack.push(val);
        }
    }

    while(!tempStack.isEmpty())
    {
        stack.push(tempStack.pop());
    }
    
    return stack;
}
