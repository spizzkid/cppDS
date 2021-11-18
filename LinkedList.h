//
// Created by spizzkid on 2021/11/16.
//

#ifndef UNTITLED_LINKEDLIST_H
#define UNTITLED_LINKEDLIST_H

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* nextElement;

    Node() {
        nextElement = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    Node* getHead();
    bool isEmpty();
    bool printList();
    void insertAtHead(int value);
    std::string elements();
    void insertAtTail(int value);
    bool search(int value);
    bool deleteAtHead();
    bool Delete(int value);
    int length();
    string reverse();
    void insertLoop();
    bool detectLoop();
    int findMid();
    string removeDuplicates();
    string Union(LinkedList list1, LinkedList list2);
    string Intersection(LinkedList list1, LinkedList list2);
    int findNth(int n);
};


#endif //UNTITLED_LINKEDLIST_H
