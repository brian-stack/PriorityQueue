#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "heap.h"
#include "info.h"
using namespace std;

template <typename T>
class PQueue
{
    //define the insertion operator for PQueue
    friend ostream& operator <<(ostream& outs, const PQueue<T>& print_me)
    {
        outs << print_me.heap;
        return outs;
    }
public:
    PQueue();
    void insert(const T& value, int p); //inserts a new info object with the recieved value and priority to the heap.
    T pop();                            //pops the info object at the top of the heap and returns its value member.
    bool isEmpty() const;               //returns true if heap is empty, otherwise false.
    size_t size() const;                //returns heap._size
    size_t capacity() const;            //returns heap._capacity

private:
    Heap<info<T> > heap;
};

//preconditions: none
//postconditions: the default constructor for heap is called.
template<typename T>
PQueue<T>::PQueue()
{
    heap;
}

//preconditions: none.
//postcontions: the item at the top of the heap is popped
//  and its item is returned to the caller.
template <typename T>
T PQueue<T>::pop()
{
    return heap.pop().item;
}

//preconditions: none.
//postcontions: a new object of type info is constructed,
//  with priority = p, item  = value and inserted into the heap.
template<typename T>
void PQueue<T>::insert(const T &value, int p)
{
    heap.insert(info<T>(value,p));
}

//preconditions: none.
//postcontions: if the size of the heap is 0,
//   return true, otherwise return false.
template<typename T>
bool PQueue<T>::isEmpty() const
{
    return heap.isEmpty();
}

//preconditions: none.
//postcontions: the current size of the heap is returned.
template<typename T>
size_t PQueue<T>::size() const
{
    return heap.size();
}

//preconditions: none.
//postcontions: the current capacity of the heap is returned.
template<typename T>
size_t PQueue<T>::capacity() const
{
    return heap.capacity();
}

#endif // PRIORITYQUEUE_H
