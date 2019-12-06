#ifndef INFO_H
#define INFO_H

#include <iostream>
using namespace std;

template <typename T>
struct info
{
    T item;
    int priority;

    info(): item(T()), priority(0) {}         //construct info with priority 0 and item T(),
    info(T i, int p): item(i), priority(p) {} //construct this info with priority p and item i

    //define insertion operator for info objects.
    friend ostream& operator <<(ostream& outs, const info<T>& print_me)
    {
        outs << "|" << print_me.item << "|" << "p = " << print_me.priority;
        return outs;
    }

    //return true if the priority of the lhs is less than that of the rhs, otherwise false.
    friend bool operator <(const info<T>& lhs, const info<T>& rhs)
    {
        return (lhs.priority < rhs.priority);
    }

    //return true if the priority of the lhs is greater than that of the rhs, otherwise false.
    friend bool operator >(const info<T>& lhs, const info<T>& rhs)
    {
        return (lhs.priority > rhs.priority);
    }
};


#endif // INFO_H
