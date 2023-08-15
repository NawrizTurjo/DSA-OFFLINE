#include <iostream>
using namespace std;
// #include "2105032_1_a_queue.cpp"
#include "2105032_1_ll_queue.cpp"
int main()
{
    Queue<int> q;
    q.print();
    while (1)
    {
        int Q, P;
        // q.print();
        cin >> Q;
        // enqueue
        if (Q == 1)
        {
            cin >> P;
            q.enqueue(P);
            q.print();
        }
        // dequeue
        else if (Q == 2)
        {
            if (q.length() != 0)
            {
                cout << q.dequeue() << endl;
                q.print();
            }
            else
                cout << "queue is empty" << endl;
        }
        // length
        else if (Q == 3)
        {
            cout << q.length() << endl;
            q.print();
        }
        // front
        else if (Q == 4)
        {
            if (q.length() != 0)
            {
                cout << q.front() << endl;
                q.print();
            }
            else
                cout << "queue is empty" << endl;
        }
        // back
        else if (Q == 5)
        {
            if (q.length() != 0)
            {
                cout << q.back() << endl;
                q.print();
            }
            else
                cout << "queue is empty" << endl;
        }
        // is_empty
        else if (Q == 6)
        {
            q.is_empty() ? cout << "True" << endl : cout << "False" << endl;
            q.print();
        }
        // clear
        else if (Q == 7)
        {
            q.clear();
            q.print();
        }
        // exit condition
        else if (Q == 0)
            break;
    }
    return 0;
}