//
// Created by spizzkid on 6/8/21.
//

#ifndef UNTITLED_MYQUEUE_H
#define UNTITLED_MYQUEUE_H


class myQueue {
private:
    int *queueArr;
    int capacity;
    int numElements;
    int front;
    int back;
public:
    myQueue(int);
    bool isEmpty();
    int getFront();
    void enqueue(int);
    int dequeue();
    int getSize();
    void showQueue();
};


#endif //UNTITLED_MYQUEUE_H
