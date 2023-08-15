#include <iostream>
using namespace std;
//#include "2105032_1_a_queue.cpp"
#include "2105032_1_ll_queue.cpp"
template <typename T>
class Stack
{
    Queue<T> q;

public:
    void clear()
    {
        q.clear();
    }
    // void push (T it)
    //{
    //     int size = q.length();
    //     q.enqueue(it);
    //     for(int i = 0;i< size;i++)
    //     {
    //         q.enqueue(q.front());
    //         q.dequeue();
    //     }
    // }
    // T pop()
    //{
    //     T popped = q.dequeue();
    //     return popped;
    // }
    void push(T it)
    {
        q.enqueue(it);
    }
    T pop()
    {
        int size = q.length();
        for (int i = 0; i < size - 1; i++)
        {
            q.enqueue(q.front());
            q.dequeue();
        }
        T popped = q.dequeue();
        return popped;
    }
    int length()
    {
        return q.length();
    }
    T topValue()
    {
        return q.front();
    }
    bool isEmpty()
    {
        return q.is_empty();
    }
    void PrintStack()
    {
        q.print();
    }
};