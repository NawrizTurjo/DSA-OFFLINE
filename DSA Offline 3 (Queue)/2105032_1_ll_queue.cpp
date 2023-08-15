#include <iostream>
using namespace std;
#include "2105032_1_ll_queue.h"
#define List Llist
template <typename T>
class Queue
{
    List<T> list;

public:
    Queue()
    {
        list.init();
    }
    void enqueue(T P)
    {
        list.moveToEnd();
        list.insert(P);
    }
    T dequeue()
    {
        if (list.length() == 0)
        {
            cout << "List is Empty" << endl;
            return -1;
        }
        list.moveToStart();
        T removed = list.remove();
        return removed;
    }
    int length()
    {
        return list.length();
    }
    T front()
    {
        if (list.length() == 0)
        {
            cout << "List is Empty" << endl;
            return -1;
        }
        list.moveToStart();
        return list.getValue();
    }
    T back()
    {
        if (list.length() == 0)
        {
            cout << "List is Empty" << endl;
            return -1;
        }
        list.moveToEnd();
        return list.getValue();
    }
    bool is_empty()
    {
        return (list.length() == 0);
    }
    void clear()
    {
        list.clear();
    }
    void print()
    {
        list.print();
    }
};