#include <iostream>
#include "2105032_2_stack.h"
using namespace std;

template <typename T>
void stackFn()
{
    Stack<T> S;
    S.PrintStack();
    int fnNo;
    T push_item;
    while (1)
    {
        cin >> fnNo;
        if (fnNo == 1)
        {
            S.clear();
            S.PrintStack();
        }
        else if (fnNo == 2)
        {
            cin.ignore();
            cin >> push_item;
            S.push(push_item);
            S.PrintStack();
        }
        else if (fnNo == 3)
        {
            if (!S.isEmpty())
            {
                cout << S.pop() << endl;
                S.PrintStack();
            }
            else
                cout << "Stack is Empty" << endl;
        }
        else if (fnNo == 4)
        {
            cout << S.length() << endl;
            S.PrintStack();
        }
        else if (fnNo == 5)
        {
            if (!S.isEmpty())
            {
                cout << S.topValue() << endl;
                S.PrintStack();
            }
            else
                cout << "Stack is Empty" << endl;
        }
        else if (fnNo == 6)
        {
            cout << (S.isEmpty() ? "True" : "False") << endl;
            S.PrintStack();
        }
        else if (fnNo == 0)
            break;
    }
}

int main()
{
    string data_type = "char";
    //cin >> data_type;
    if (data_type == "int")
    {
        stackFn<int>();
    }
    else if (data_type == "char")
    {
        stackFn<char>();
    }
    else if (data_type == "double")
    {
        stackFn<double>();
    }
    return 0;
}