#include <iostream>
#include "stack.cpp"
using namespace std;

template <typename T>
void stackFn()
{
    int mem_chunk, initial_length;
    cin >> mem_chunk >> initial_length;
    Stack<T> S(mem_chunk);
    for (int i = 0; i < initial_length; i++)
    {
        T j;
        cin >> j;
        S.push(j);
    }
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
        }
        else if (fnNo == 5)
        {
            if (!S.isEmpty())
            {
                cout << S.topvalue() << endl;
            }
            else
                cout << "Stack is Empty" << endl;
        }
        else if (fnNo == 6)
        {
            cout << (S.isEmpty() ? "True" : "False") << endl;
        }
        else if (fnNo == 0)
            break;
    }
}

int main()
{
    string data_type;
    cin >> data_type;
    if (data_type == "int")
    {
        stackFn<int>();
    }
    else if (data_type == "char")
    {
        stackFn<char>();
    }
    return 0;
}

/*
char
10 5
a b c d e
1
2 e
3
4
2 f
5
6
0

*/

/*
int
10 5
1 2 3 4 5
1
2 4
3
4
2 5
5
6
0

*/
/*
char
10 5
a b c d e
2 m
3
4
5
6
1
6
0

*/