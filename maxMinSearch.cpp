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
node *CreateTree()
{
    node *root = NULL;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    root->left = CreateTree();
    root->right = CreateTree();
    return root;
}

bool findInTree(int val,node*root)
{
    if(!root)
    {
        return false;
    }
    if(root->data==val)
    {
        return true;
    }
    return (findInTree(val,root->left) | findInTree(val,root->right));
}

int main()
{
    node* root = CreateTree();
    while (true)
    {
        int data;
        cin>>data;
        if(data==-100)
        {
            break;
        }
        if(findInTree(data,root))
        {
            cout<<"Element is present in the tree"<<endl;
        }
        else
        {
            cout<<"Element is not present in the tree"<<endl;
        }
    }

    
    return 0;
}
