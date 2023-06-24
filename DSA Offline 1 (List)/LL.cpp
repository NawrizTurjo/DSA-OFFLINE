#include <iostream>
using namespace std;
#define defaultsize 1
struct Node
{
    int data;
    Node *next;
};
class Llist
{
    Node *head;
    Node *curr;
    Node *tail;
    int listSize;
    void removeall()
    {
        while (head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
    void add(int it)
    {
        tail->next = new Node;
        tail->next->data = it;
        tail->next->next = NULL;
        tail = tail->next;
        listSize++;
        // print();
    }

public:
    Llist()
    {
        curr = tail = head = new Node;
        tail->next = NULL;
        listSize = 0;
    }
    void init()
    {
        // curr = tail = head = new Node;
        //  tail->next=NULL;
        listSize = 0;
        int size;
        int mem_chunk;
        cin >> size >> mem_chunk;
        for (int i = 0; i < size; i++)
        {
            int j;
            cin >> j;
            add(j);
        }
        // print();
    }
    ~Llist()
    {
        removeall();
    }
    void print()
    {
        Node *temp = head->next;
        // if (currPos() == 0)
        //{
        //     cout << "|";
        // }
        cout << "<";
        while (temp != NULL && listSize != 0)
        {
            if (temp == curr->next)
            {
                cout << " | " << temp->data;
            }
            else if (temp != head->next)
            {
                cout << ", " << temp->data;
            }
            else
            {
                cout << temp->data;
            }
            temp = temp->next;
        }
        cout << ">" << '\n';
        // cout<<"Printing Currnent Node: "<<curr->data<<"\t"<<"Printing Currnet data: "<<curr->next->data<<"\n";
    }
    void insert(int it)
    {
        if (curr->next == NULL)
        {
            Node *newNode = new Node;
            tail->next = newNode;
            newNode->data = it;
            newNode->next = NULL;
            tail = newNode;
            listSize++;
            // print();
            return;
        }
        Node *newNode = new Node;
        newNode->data = it;
        newNode->next = curr->next;
        curr->next = newNode;
        listSize++;
        // print();
    }
    int remove()
    {
        if (listSize == 0)
            return -1;
        int toRemove = curr->next->data;
        Node *tempNode = curr->next;
        if (tail == curr->next)
        {
            tail = curr;
            tail->next = NULL;
            prev();
        }
        else
        {
            curr->next = curr->next->next;
        }
        delete tempNode;
        listSize--;
        // print();
        return toRemove;
    }
    void moveToStart()
    {
        curr = head;
    }
    void moveToEnd()
    {
        curr = tail;
        prev();
        // print();
    }
    void prev()
    {
        if (curr == head)
            return;
        Node *temp = head;
        while (temp->next != curr)
        {
            temp = temp->next;
        }
        curr = temp;
    }
    void next()
    {
        if (curr->next == tail)
            return;
        curr = curr->next;
    }
    int length()
    {
        return listSize;
    }
    int currPos()
    {
        Node *temp = head;
        int count = 0;
        while (temp != curr)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    void moveToPos(int pos)
    {
        if (pos < 0 || pos >= listSize)
        {
            cout << "Error!" << endl;
            return;
        }
        curr = head;
        for (int i = 0; i < pos; i++)
        {
            curr = curr->next;
        }
    }
    int getValue()
    {
        if (curr->next != NULL)
            return curr->next->data;
        return -1;
    }
};