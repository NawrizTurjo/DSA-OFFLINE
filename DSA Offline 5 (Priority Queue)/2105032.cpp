#include <iostream>
#include <cmath>
#include<string>
#include "maxPriorityQ.hpp"
using namespace std;
#define DATATYPE int
 
int main()
{
    priorityQueue<DATATYPE> pq;
    FILE *fin = freopen("in2.txt", "r", stdin);
    FILE *fout = freopen("out_test2.txt", "w", stdout);
    char ch;
    while (cin >> ch)
    {
        if (ch == '1')
        {
            DATATYPE insert;
            cin >> insert;
            pq.Insert(insert);
        }
        else if (ch == '2')
        {
            cout << "Max: " << pq.FindMax() << endl;
        }
        else if (ch == '3')
        {
            pq.ExtractMax();
        }
        else if (ch == '4')
        {
            int i1;
            DATATYPE key1;
            cin >> i1 >> key1;
            pq.IncreaseKey(i1, key1);
        }
        else if (ch == '5')
        {
            int i2;
            DATATYPE key2;
            cin >> i2 >> key2;
            pq.DecreaseKey(i2, key2);
        }
        else if (ch == '6')
        {
            pq.Print();
        }
        else if (ch == '7')
        {
            pq.Sort();
        }
    }

    return 0;
}