#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void PreOrder(node *n)
{
    if (!n)
    {
        return;
    }
    cout << n->data << " ";
    PreOrder(n->left);
    PreOrder(n->right);
}

void InOrder(node *n)
{
    if (!n)
    {
        return;
    }
    InOrder(n->left);
    cout << n->data << " ";
    InOrder(n->right);
}

void PostOrder(node *n)
{
    if (!n)
    {
        return;
    }
    PostOrder(n->left);
    PostOrder(n->right);
    cout << n->data << " ";
}

int main()
{
    node *n = new node(1);
    n->left = new node(2);
    n->right = new node(3);
    n->left->left = new node(4);
    n->left->right = new node(5);
    n->right->left = new node(6);
    n->right->right = new node(7);
    PreOrder(n);
    cout << endl;
    InOrder(n);
    cout << endl;
    PostOrder(n);
    cout << endl;
    return 0;
}
