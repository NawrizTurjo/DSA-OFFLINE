#include <iostream>
using namespace std;
#define defaultsize 1
class AList
{
    int maxsize;
    int listsize;
    int curr;
    int *listarray;
    void reallocate_array_size(int size)
    {
        maxsize = 2 * size;
        int *new_listarray = new int[maxsize];
        for (int i = 0; i < size; i++)
        {
            new_listarray[i] = listarray[i];
        }
        delete[] listarray;
        listarray = new_listarray;
    }
    void add(int it)
    {
        if (listsize >= maxsize)
        {
            reallocate_array_size(maxsize);
        }
        listarray[listsize] = it;
        listsize++;
        // print();
    }

public:
    AList()
    {
        listsize = 0;
        curr = 0;
        maxsize = defaultsize;
        listarray = new int[maxsize];
    }
    void init()
    {
        int size;
        cin >> size >> maxsize;
        listsize = 0;
        curr = 0;
        listarray = new int[maxsize];
        for (int i = 0; i < size; i++)
        {
            int j;
            cin >> j;
            add(j);
        }
    }
    ~AList()
    {
        delete[] listarray;
    }
    void print()
    {
        cout << "<";
        for (int i = 0; i < listsize; i++)
        {
            if (curr == i && listsize > 0)
            {
                cout << " | ";
            }
            else if (curr != i && i != 0 && i < listsize)
            {
                cout << ", ";
            }
            cout << listarray[i];
        }
        cout << ">\n";
    }
    void insert(int it)
    {
        if (listsize >= maxsize)
        {
            reallocate_array_size(maxsize);
        }
        for (int i = listsize; i > curr; i--)
        {
            listarray[i] = listarray[i - 1];
        }
        listarray[curr] = it;
        listsize++;
        // print();
    }
    int remove()
    {
        if (listsize == 0)
            return -1;
        int it = listarray[curr];
        for (int i = curr; i < listsize - 1; i++)
        {
            listarray[i] = listarray[i + 1];
        }
        if (curr == listsize - 1)
        {
            curr--;
        }
        listsize--;
        // cout<<"Remove: ";
        // print();
        return it;
    }
    void moveToStart()
    {
        curr = 0;
    }
    void moveToEnd()
    {
        curr = listsize - 1;
    }
    void prev()
    {
        if (curr != 0)
            curr--;
    }
    void next()
    {
        if (curr < listsize - 1)
        {
            curr++;
        }
        // print();
    }
    int length()
    {
        return listsize;
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
        curr = pos;
        // print();
    }
    int getValue()
    {
        return listarray[curr];
    }
};