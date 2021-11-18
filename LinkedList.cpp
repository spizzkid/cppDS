//
// Created by spizzkid on 2021/11/16.
//
#include "LinkedList.h"



LinkedList::LinkedList() {
    head = nullptr;
}

Node *LinkedList::getHead() {
    return head;
}

bool LinkedList::isEmpty() {
    if (head == nullptr)
        return true;
    else
        return false;
}

bool LinkedList::printList() {
    if (isEmpty())
    {
        cout << "List is empty!" << endl;
        return false;
    }
    Node* temp = head;  //starting from head node
    cout << "List : ";

    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->nextElement;
    }

    cout << "NULL \n";

    return true;
}

void LinkedList::insertAtHead(int value) {
    Node* newNode = new Node();     // creating new node
    newNode->data = value;
    newNode->nextElement = head;
    head = newNode;
    cout << value << " Inserted!";
}

void LinkedList::insertAtTail(int value) {
    if (isEmpty())
    {
        insertAtHead(value);
    }
    else
    {
        Node* newNode = new Node();
        Node* last = head;      // last pointing to head of the list

        while (last->nextElement != nullptr)      // traversing through list
        {
            last = last->nextElement;
        }

        newNode->data = value;
        cout << value << " Inserted!     ";
        newNode->nextElement = nullptr;
        last->nextElement = newNode;
    }
}

std::string LinkedList::elements() {        // this function will return all values of linked list
    string elementsList;
    Node* start = head;
    Node* check = head;

    elementsList += to_string(start->data);
    elementsList += "->";
    start = start->nextElement;

    while (start != nullptr && start->data != check->data)
    {
        elementsList += to_string(start->data);
        elementsList += "->";
        start = start->nextElement;
    }

    if (start == nullptr)
    {
        return elementsList += "null";
    }
    elementsList += to_string(check->data);

    return elementsList;
}

bool LinkedList::search(int value) {
    Node* temp = head;

    while (temp->nextElement != nullptr)
    {
        if (temp->data == value)
        {
            return true;
        }
        else
            temp = temp->nextElement;
    }
    return false;
}

bool LinkedList::deleteAtHead() {
    if (isEmpty())
    {
        cout << "List is empty\n";
        return false;
    }
    Node* currentNode = head;
    head = head->nextElement;

    delete currentNode;
    return true;
}

bool LinkedList::Delete(int value) {
    bool deleted = false;

    if (isEmpty())
    {
        cout << "List is empty! ";
        return deleted;
    }

    // if list is not empty, traversing from the head
    Node* currentNode = head;
    Node* previousNode = nullptr;

    if (currentNode->data == value)     // deleting value from head (if found in the head)
    {
        deleted = deleteAtHead();
        cout << value << " deleted!\n";
        deleted = true;
        return deleted;
    }
    previousNode = currentNode;
    currentNode = currentNode->nextElement;

    while (currentNode != nullptr)
    {
        if (currentNode->data == value)
        {
            previousNode->nextElement = currentNode->nextElement;
            delete currentNode;
            currentNode = previousNode->nextElement;
            deleted = true;
            break;
        }
        previousNode = currentNode;
        currentNode = currentNode->nextElement;
    }

    if (!deleted)
        cout << value << " does not deleted!\n";
    else
        cout << value << " deleted!\n";
    return deleted;
}   // end of deleted()

int LinkedList::length() {
    Node* temp = head;
    int len = 0;
    while (temp != nullptr)
    {
        temp = temp->nextElement;
        len++;
    }
    return len;
}

string LinkedList::reverse() {
        Node* previous = nullptr;
        Node* current = head;
        Node* next = nullptr;

        // while traversing list, swap links
        while (current != nullptr)
        {
            next = current->nextElement;
            current->nextElement = previous;
            previous = current;
            current = next;
        }

        head = previous;
        return elements();
}

bool LinkedList::detectLoop() {
    Node* slow = head, * fast = head;       // starting head of list

    while (slow && fast && fast->nextElement)
    {
        slow = slow->nextElement;
        fast = fast->nextElement->nextElement;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

void LinkedList::insertLoop() {
    Node* temp = head;
    // traversing to get last element of list
    while (temp->nextElement != nullptr)
    {
        temp = temp->nextElement;
    }
    temp->nextElement = head;       // pointing last element to head of list
}

int LinkedList::findMid() {
    if (isEmpty())
        return 0;

    Node* currentNode = head;

    if (currentNode->nextElement == nullptr)
    {
        return currentNode->data;
    }

    Node* midNode = currentNode;    // midNode started at head
    currentNode = currentNode->nextElement->nextElement;        // currentNode moves two steps forward

    //Move midNode (Slower) one step at a time
    //Move currentNode (Faster) two steps at a time
    //When currentNode reaches at end, midNode will be at the middle of List
    while (currentNode != nullptr)
    {
        midNode = midNode->nextElement;

        currentNode = currentNode->nextElement;
        if (currentNode != nullptr)
            currentNode = currentNode->nextElement;
    }
    if (midNode != nullptr)
    {
        return midNode->data;
    }
    return 0;
}

string LinkedList::removeDuplicates() {
    struct Node* start, * startNext, * dup;
    start = head;

    // pick elements one by one
    while (start != nullptr && start->nextElement != nullptr) {
        startNext = start;

        // compare picked element with rest of the elements
        while (startNext->nextElement != nullptr) {
            // if duplicate then delete it
            if (start->data == startNext->nextElement->data) {
                /* sequence of steps is important here */
                dup = startNext->nextElement;   // picking duplicate
                // skipping elements from list to be deleted
                startNext->nextElement = startNext->nextElement->nextElement;
                delete (dup);
            } else
                startNext = startNext->nextElement;
        }
        start = start->nextElement;
    }
    return elements();
}

string LinkedList::Union(LinkedList list1, LinkedList list2) {
    if (list1.isEmpty())
        return list2.elements();
    else if (list2.isEmpty())
        return list1.elements();

    Node* start = list1.head;   // starting from head of list1

    while (start->nextElement != nullptr)
    {
        start = start->nextElement;
    }
    start->nextElement = list2.head;

    return list1.removeDuplicates();
}


string LinkedList::Intersection(LinkedList list1, LinkedList list2) {
    LinkedList list3;
    Node* t1 = list1.head, *t2 = list2.head;

    // traverse both lists and store same element in list3
    while (t1 != nullptr) {
        while (t2 != nullptr) {
            if (t1->data == t2->data)
                list3.insertAtTail(t1->data);
            else
                t2 = t2->nextElement;
        }
        t2 = list2.head;
        t1 = t1->nextElement;
    }
    list3.removeDuplicates();
    return list3.elements();
}

int LinkedList::findNth(int n) {
    if (isEmpty())
        return -1;
    int length = 0;
    Node* currentNode = head;

    while (currentNode != nullptr)
    {
        currentNode = currentNode->nextElement;
        length++;
    }
    currentNode = head;
    int position = length - n;

    if (position < 0 || position > length)      // check range of position
        return -1;

    int count = 0;

    while (count < position)
    {
        currentNode = currentNode->nextElement;
        count++;
    }

    if (currentNode != nullptr)
        return currentNode->data;

    return -1;

}