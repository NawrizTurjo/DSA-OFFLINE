#include <iostream>
using namespace std;
#include "Arr.cpp"
#include "LL.cpp"
#define List AList
int main()
{
    List list;
    list.init();
    while (1)
    {
        int Q, P;
        cin >> Q >> P;
        // clear
        if (Q == 1)
        {
            list.moveToStart();
            while (list.length() != 0)
            {
                list.remove();
            }
            list.print();
            list.init();
            list.print();
        }
        // append
        else if (Q == 2)
        {
            if (list.length() == 0)
                list.insert(P);
            else
            {
                int temp = list.currPos();
                list.moveToEnd();
                int remember = list.getValue();
                list.insert(P);
                list.moveToEnd();
                list.remove();
                list.insert(remember);
                list.moveToPos(temp);
            }
            list.print();
        }
        // search
        else if (Q == 3 || Q == 4)
        {
            int is_found = -1;
            int temp = list.currPos();
            list.moveToStart();
            for (int i = 0; i < list.length(); i++)
            {
                if (list.getValue() == P)
                {
                    is_found = list.currPos() + 1;
                    break;
                }
                list.next();
            }
            list.moveToPos(temp);
            if (is_found > -1)
            {
                cout << is_found - 1 << endl;
            }
            else
                cout << is_found << endl;
        }
        else if (Q == 0)
            break;
    }
    return 0;
}