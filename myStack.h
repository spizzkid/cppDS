//
// Created by spizzkid on 6/7/21.
//

#ifndef UNTITLED_MYSTACK_H
#define UNTITLED_MYSTACK_H


class myStack {
private:
    int *stackArr;
    int capacity;
    int numElements;
public:
    myStack(int size);
    bool isEmpty();
    int getTop();
    bool push(int value);
    int pop();
    int getSize();
    void showStack();
    myStack sortStack(myStack stack, int size);
};


class twoStacks
{
private:
    int size;
    int *arr;
    int top1, top2;
public:
    twoStacks(int n)
    {
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int val)
    {
        if (top1 < top2 -1)
        {
            arr[++top1] = val;
        }

    }

    void push2(int val)
    {
        if(top1 < top2 -1 )
        {
            arr[--top2] = val;
        }
    }

    int pop1()
    {
        // get value from top1 index and increment it.
        if(top1 >= 0)
        {
            int val = arr[top1--];
            return val;
        }
        return -1;
    }

    int pop2()
    {
        if (top2 < size)
        {
            int val = arr[top2++];
            return val;
        }
        return -1;
    }


};


#endif //UNTITLED_MYSTACK_H
