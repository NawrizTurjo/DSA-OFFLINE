#include <iostream>
using namespace std;
#include "Arr.cpp"
#include "LL.cpp"
#define List Llist
int main()
{
    List list;
    list.init();
    while (1)
    {
        int Q, P;
        cin >> Q >> P;
        if (Q == 1)
        {
            list.insert(P);
            list.print();
        }
        else if (Q == 2)
        {
            cout << list.remove() << endl;
            list.print();
        }
        else if (Q == 3)
        {
            list.moveToStart();
            list.print();
        }
        else if (Q == 4)
        {
            list.moveToEnd();
            list.print();
        }
        else if (Q == 5)
        {
            list.prev();
            list.print();
        }
        else if (Q == 6)
        {
            list.next();
            list.print();
        }
        else if (Q == 7)
        {
            cout << list.length() << endl;
            list.print();
        }
        else if (Q == 8)
        {
            cout << list.currPos() << endl;
            list.print();
        }
        else if (Q == 9)
        {
            list.moveToPos(P);
            list.print();
        }
        else if (Q == 10)
        {
            cout << list.getValue() << endl;
            list.print();
        }
        else if (Q == 0)
            break;
    }
    return 0;
}