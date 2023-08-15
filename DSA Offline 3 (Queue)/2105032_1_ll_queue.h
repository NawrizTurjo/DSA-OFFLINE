#include <iostream>
using namespace std;
#define defaultsize 0
template <typename T>
struct Node
{
    T data;
    Node *next;
};
template <typename T>
class Llist
{
    Node<T> *head;
    Node<T> *curr;
    Node<T> *tail;
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
    void add(T it)
    {
        tail->next = new Node<T>;
        tail->next->data = it;
        tail->next->next = NULL;
        tail = tail->next;
        listSize++;
        // print();
    }

public:
    Llist()
    {
        curr = tail = head = new Node<T>;
        tail->next = NULL;
        listSize = 0;
    }
    void init()
    {
        // curr = tail = head = new Node<T>;
        // tail->next=NULL;
        // listSize = 0;
        // int size;
        // int mem_chunk;
        // cin >> size >> mem_chunk;
        // for (int i = 0; i < size; i++)
        //{
        //     T j;
        //     cin >> j;
        //     add(j);
        // }
        // print();
    }
    // change
    ~Llist()
    {
        removeall();
    }
    void print()
    {
        Node<T> *temp = head->next;
        // if (currPos() == 0)
        //{
        //     cout << "|";
        // }
        cout << "<";
        while (temp != NULL && listSize != 0)
        {
            if(temp->next!=NULL)
                cout<<temp->data<<", ";
            else
                cout<<temp->data;
            temp = temp->next;
        }
        cout << ">" << '\n';
        // cout<<"Printing Currnent Node: "<<curr->data<<"\t"<<"Printing Currnet data: "<<curr->next->data<<"\n";
    }
    void insert(T it)
    {
        if (curr->next == NULL)
        {
            Node<T> *newNode = new Node<T>;
            tail->next = newNode;
            newNode->data = it;
            newNode->next = NULL;
            tail = newNode;
            listSize++;
            // print();
            return;
        }
        Node<T> *newNode = new Node<T>;
        newNode->data = it;
        newNode->next = curr->next;
        curr->next = newNode;
        listSize++;
        // print();
    }
    T remove()
    {
        if (listSize == 0)
            return -1;
        T toRemove = curr->next->data;
        Node<T> *tempNode = curr->next;
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
        // prev();
        // print();
    }
    void prev()
    {
        if (curr == head)
            return;
        Node<T> *temp = head;
        while (temp->next != curr)
        {
            temp = temp->next;
        }
        curr = temp;
    }
    void next()
    {
        if (curr == tail)
            return;
        curr = curr->next;
    }
    int length()
    {
        return listSize;
    }
    int currPos()
    {
        Node<T> *temp = head;
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
    T getValue()
    {
        if (curr->next != NULL)
            return curr->next->data;
        return curr->data;
    }
    void clear()
    {
        moveToStart();
        while (length() != 0)
        {
            remove();
        }
        //print();
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
        print();
    }
};