
#include <iostream>
#include "myStack.h"
#include "myQueue.h"
#include <algorithm>
#include "LinkedList.h"

using namespace std;



int main()
{
    LinkedList list, list1;  // creating lists
    int rand_num = rand() % 5 + 1;
    srand (time(NULL));

    cout << "List 1 " << endl;
    for(int i = 1; i<5 ; i++) {
        rand_num = rand() % 5 + 1;
        list.insertAtHead(rand_num);    // inserting value in the list
    }
    list.printList();

    cout << "List 2 " << endl;
    for(int i = 4; i<8 ; i++) {
        rand_num = rand() % 5 + 1;
        list1.insertAtHead(rand_num);    // inserting value in the list
    }
    list1.printList();
    string check = list.Union(list , list1);  // calling union function
    cout << "Union List : "<< check << endl;
    return 0;
}



