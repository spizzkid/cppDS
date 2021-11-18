//
// Created by spizzkid on 6/8/21.
//

#include "myQueue.h"
#include <cassert>
#include <iostream>

using namespace std;

myQueue::myQueue(int size) {
    capacity = size;
    queueArr = new int[size];
    assert(queueArr != NULL);
    numElements = 0;
    front = 0;
    back = -1;
}

bool myQueue::isEmpty() {
    return (numElements == 0);
}

int myQueue::getFront() {
    if(isEmpty())
    {
        cout << "Queue Empty\n";
        return -1;
    }
    else
    {
        return queueArr[front];
    }
}

void myQueue::enqueue(int value) {
    if (numElements == capacity)
    {
        cout << "Queue Full\n";
        return;
    }

    if (back == capacity - 1)
        back = -1;

    queueArr[++back] = value;
    numElements++;
}

int myQueue::dequeue() {
    if (isEmpty())
    {
        cout << "Queue Empty\n";
        return -1;
    }
}