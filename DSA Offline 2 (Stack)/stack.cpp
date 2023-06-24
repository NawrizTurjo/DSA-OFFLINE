#include <iostream>
using namespace std;
#define defaultSize 1
template <typename N>
class Stack
{
    int maxSize;
    int top;
    N *stackArray;
    void reallocate_array_size(int size)
    {
        maxSize = 2 * size;
        N *new_Stackarray = new N[maxSize];
        for (int i = 0; i < size; i++)
        {
            new_Stackarray[i] = stackArray[i];
        }
        delete[] stackArray;
        stackArray = new_Stackarray;
    }

public:
    Stack(int size = defaultSize)
    {
        maxSize = size;
        top = 0;
        stackArray = new N[size];
    }
    ~Stack()
    {
        top = 0;
        delete[] stackArray;
    }
    void clear()
    {
        top = 0;
    }
    void push(N it)
    {
        if (top >= maxSize)
        {
            reallocate_array_size(maxSize);
        }
        stackArray[top++] = it;
    }
    N pop()
    {
        if (top > 0)
        {
            return stackArray[--top];
        }
        return -1;
    }
    int length()
    {
        return top;
    }
    N topvalue()
    {
        if (top > 0)
        {
            return stackArray[top - 1];
        }
        return -1;
    }
    bool isEmpty()
    {
        return top == 0;
    }
    void PrintStack()
    {
        cout << "<";
        for (int i = 0; i < top; i++)
        {
            cout << stackArray[i];
            if (i != top - 1)
            {
                cout << ", ";
            }
        }
        cout << ">\n";
    }
};
