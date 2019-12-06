/*************************************************************************************************************************
 * Author: Brian Stack
 * Assignment: Priority Queue
 * Date: 10/15/18
 * Class: CS 8
 * CRN: 74231
 * ***********************************************************************************************************************
 * This program tests that items are correctly inserted into, and removed from, a priority queue.
 *  The priority queue class is built on the heap class, and for most priority queue operations, the queue simply
 *    calls the corresponding heap member.
 *  - PQueue Insert: constructs a new info object with the recieved priority and value, and calls heap insert,
 *    which inserts the info item at the end of heap's array. Reheapup is then called, restoring the max-heap property.
 *  - PQueue Pop: calls heap pop which replaces the info object at the start of the array with the one at the end of the
 *    array, thereby removing the first item from the heap and returning the removed item. Reheapdown is then called,
 *    restoring the max-heap property.
 ************************************************************************************************************************/

#include <iostream>
#include <random>
#include <ctime>
#include "priorityqueue.h"
using namespace std;

const int P_QUEUE_MAX = 100;
const int MAX_PRIORITY = 10;
const int MAX_ITEMS = 15;

int main()
{
    srand(time(0));
    PQueue<int> pq;

    cout << "Inserting " << MAX_ITEMS << " random items to the priority queue." << endl
         <<string(50,'=') << endl;

    //test priority queue by inserting 15 info items with: 1<=value<=100, 1<=priority<=15
    // note that the heap remains a max heap when items are inserted
    for (size_t i = 0; i< MAX_ITEMS; i++)
    {
        int value = (rand() % P_QUEUE_MAX) + 1;
        int priority = (rand() % MAX_PRIORITY) + 1;
        cout << "Inserting item with: value = " << value << ", priority = " << priority << endl;
        pq.insert(value,priority);
        cout << pq << endl << string(50,'-') << endl;
    }

    cout << endl << "Popping all items from the priority queue." << endl
         <<string(50,'=') << endl;
    //pop each item from the queue until it is empty
    // note that the heap remains a max heap when items are removed
    while(!pq.isEmpty())
    {
        cout << "Popped: " << pq.pop() << endl
             << pq << endl << string(50,'-') << endl;
    }

    return 0;
}
