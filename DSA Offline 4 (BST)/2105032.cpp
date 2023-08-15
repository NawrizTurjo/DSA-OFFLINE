#include<iostream>
using namespace std;
#include "bst.hpp"

int main()
{
    FILE *fin = freopen("in.txt", "r", stdin);
    FILE *fout = freopen("out.txt", "w", stdout);
    BST Tree;
    char ch;
    while (cin >> ch)
    {
        string str;
        cin >> str;
        if (ch == 'F')
        {
            int num = stoi(str);
            bool is_found = Tree.Find(num);
            if (is_found)
                cout << "found" << endl;
            else
                cout << "not found" << endl;
        }
        else if (ch == 'T')
        {
            if (str == "In")
            {
                Tree.inorder();
                cout << endl;
            }
            else if (str == "Pre")
            {
                Tree.preorder();
                cout << endl;
            }
            else if (str == "Post")
            {
                Tree.postorder();
                cout << endl;
            }
        }
        else if (ch == 'D')
        {
            int num = stoi(str);
            Tree.Delete(num);
            Tree.print();
            cout << endl;
        }
        else if (ch == 'I')
        {
            int num = stoi(str);
            Tree.insert(num);
            Tree.print();
            cout << endl;
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}