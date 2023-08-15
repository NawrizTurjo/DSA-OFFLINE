#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
    Node(int value)
    {
        key = value;
        left = NULL;
        right = NULL;
    }
    Node(const Node &N)
    {
        key = N.key;
        left = N.left;
        right = N.right;
    }
};

class BST
{
    Node *root;
    int nodecount;
    Node *BSTinsert(Node *root, int value)
    {
        if (root == NULL)
        {
            root = new Node(value);
            nodecount++;
        }
        else if (value > root->key)
        {
            root->right = BSTinsert(root->right, value);
        }
        else if (value <= root->key)
        {
            root->left = BSTinsert(root->left, value);
        }
        return root;
    }
    bool BSTfind(Node *root, int value)
    {
        if (root == NULL)
            return false;
        else if (root->key == value)
            return true;
        if (root->key > value)
            return BSTfind(root->left, value);
        // else if (root->key < value)
        else
            return BSTfind(root->right, value);
    }
    void BSTpreorder(Node *root)
    {
        // static int a = 0;
        if (root == NULL)
            return;
        cout << root->key<<' ';
        // a++;
        // if (a < nodecount)
        //     cout << ' ';
        BSTpreorder(root->left);
        BSTpreorder(root->right);
    }
    void BSTinorder(Node *root)
    {
        // static int a = 0;
        if (root == NULL)
            return;
        BSTinorder(root->left);
        cout << root->key<<' ';
        // a++;
        // if (a < nodecount)
        //     cout << ' ';
        BSTinorder(root->right);
    }
    void BSTpostorder(Node *root)
    {
        // static int a = 0;
        if (root == NULL)
            return;
        BSTpostorder(root->left);
        BSTpostorder(root->right);
        cout << root->key<<' ';
        // a++;
        // if (a < nodecount)
        //     cout << ' ';
    }
    Node *BSTFindMin(Node *root)
    {
        while (root->left != NULL)
            root = root->left;
        return root;
    }
    Node *BSTdeleteNode(Node *root, int value)
    {
        if (root == NULL)
            return root;
        else if (value > root->key)
            root->right = BSTdeleteNode(root->right, value);
        else if (value < root->key)
            root->left = BSTdeleteNode(root->left, value);
        else if (value == root->key)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
                nodecount--;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                Node *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                Node *temp = root;
                root = root->left;
                delete temp;
            }
            else if (root->left != NULL && root->right != NULL)
            {
                Node *temp = BSTFindMin(root->right);
                root->key = temp->key;
                root->right = BSTdeleteNode(root->right, temp->key);
            }
            nodecount--;
        }
        return root;
    }
    void BSTprint(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->key;
        if (root->left != NULL || root->right != NULL)
        {
            cout << '(';
            BSTprint(root->left);
            cout << ',';
            BSTprint(root->right);
            cout << ')';
        }
    }

public:
    BST()
    {
        root = NULL;
        nodecount = 0;
    }
    void insert(int value)
    {
        root = BSTinsert(root, value);
    }
    void Delete(int value)
    {
        root = BSTdeleteNode(root, value);
    }
    bool Find(int value)
    {
        return BSTfind(root, value);
    }
    void inorder()
    {
        BSTinorder(root);
    }
    void preorder()
    {
        BSTpreorder(root);
    }

    void postorder()
    {
        BSTpostorder(root);
    }

    void print()
    {
        cout << '(';
        BSTprint(root);
        cout << ')';
    }

    
};

