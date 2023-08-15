#include <iostream>
using namespace std;
#define defaultsize 2
template <typename T>
class AList
{
    int maxsize;
    int listsize;
    int curr;
    T *listarray;
    int front;
    int rear;
    void reallocate_array_size(int size)
    {
        // if (maxsize == 0)
        //     maxsize++;
        // maxsize = 2 * size;
        // T *new_listarray = new T[maxsize];
        // for (int i = 0; i < size; i++)
        // {
        //     new_listarray[i] = listarray[i];
        // }
        // delete[] listarray;
        // listarray = new_listarray;
        int number = (rear - front + 1 + maxsize) % maxsize;
        int prevSize = maxsize;
        maxsize = 2 * size - 1;
        T *new_listarray = new T[maxsize];
        int current = front;
        int i;
        for (i = 0; i < number; i++)
        {
            new_listarray[i + 1] = listarray[current];
            current = (current + 1) % prevSize;
        }
        front = 1;
        curr = rear = number;
        delete[] listarray;
        listarray = new_listarray;
    }

    /*
    void printQueue()
    {
        int number;
        if (front > rear)
            number = maxSize - (front - rear) + 1;
        else
            number = rear - front + 1;
        int curr = front;
        for (int i = 0; i < number; i++)
        {
            cout << listArray[curr] << ' ';
            curr++;
            if (curr == maxSize)
            curr = 0;
        }
        cout << endl;
    }
    */
    void add(T it)
    {
        if ((rear + 2) % maxsize == front)
        {
            reallocate_array_size(maxsize);
        }
        listarray[listsize - 1] = it;
        rear = (rear + 1) % maxsize;
        listsize++;
        // print();
    }

public:
    AList()
    {
        listsize = 1;
        rear = 0;
        front = 1;
        curr = front;
        maxsize = defaultsize;
        listarray = new T[maxsize];
    }
    void init()
    {
        listsize = 1;
        rear = 0;
        front = 1;
        curr = front;
        maxsize = defaultsize;
        listarray = new T[maxsize];
    }
    ~AList()
    {
        delete[] listarray;
    }
    void insert(T it)
    {
        // circular queue is full
        if (((rear + 2) % maxsize == front) || (maxsize == 1))
        {
            reallocate_array_size(maxsize);
        }
        // for (int i = listsize; i > curr; i--)
        //{
        //     listarray[i] = listarray[i - 1];
        // }
        if (curr == rear)
        {
            rear = (rear + 1) % maxsize;
        }
        listarray[rear] = it;
        listsize++;
        // print();
    }
    T remove()
    {
        if ((rear - front + 1) % maxsize == 0)
            return -1; // circular queue is empty
        T it = listarray[curr];
        // for (int i = curr; i < listsize - 1; i++)
        // {
        //     listarray[i] = listarray[i + 1];
        // }
        // if (curr == listsize - 1)
        // {
        //     curr--;
        // }
        listsize--;
        if (curr == front)
        {
            front = (front + 1) % maxsize;
        }
        // cout<<"Remove: ";
        // print();
        return it;
    }
    void moveToStart()
    {
        curr = front;
    }
    void moveToEnd()
    {
        curr = rear;
    }
    void prev()
    {
        if (curr != front)
            curr = (curr - 1 + maxsize) % maxsize;
    }
    void next()
    {
        curr = (curr + 1) % maxsize;
        // print();
    }
    int length()
    {
        return (rear - front + 1 + maxsize) % maxsize;
    }
    int currPos()
    {
        return curr;
    }
    void moveToPos(int pos)
    {
        if (pos < 0 || pos >= listsize)
        {
            cout << "Error!" << endl;
            return;
        }
        curr = (front + pos) % maxsize;
        // print();
    }
    T getValue()
    {
        return listarray[curr];
    }
    void print()
    {
        int number = (rear - front + 1 + maxsize) % maxsize;
        int current = front;
        cout << "<";
        for (int i = 0; i < number; i++)
        {
            if(i<number-1)
                cout << listarray[current] << ", ";
            else
                cout<<listarray[current];
            current = (current + 1) % maxsize;
        }
        cout << ">" << endl;
    }
    void clear()
    {
        delete []listarray;
        init();
        //print();
    }
    void append(T it)
    {
        int temp = currPos();
        moveToEnd();
        T remember = getValue();
        insert(it);
        moveToEnd();
        remove();
        insert(remember);
        moveToPos(temp);
        //print();
    }
};