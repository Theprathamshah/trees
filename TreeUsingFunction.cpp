#include<bits/stdc++.h>
using namespace std;
 
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* CreateTree()
{
    node* root = NULL;
    int data;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    root = new node(data);
    root->left = CreateTree();
    root->right = CreateTree();
    return root;
}

void Preorder(node* root)
{
    if(!root)
    {
        return;
    }
    Preorder(root->left);
    cout<<root->data<<" ";
    Preorder(root->right);
}

void InOreder(node* root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data<<" ";
    InOreder(root->left);
    InOreder(root->right);
}

int main()
{
    node* root = CreateTree();
    cout<<"Elements of tree are given below "<<endl;
    Preorder(root);
    cout<<endl;
    cout<<"Elements of tree are given below "<<endl;
    InOreder(root);
    
    return 0;
}
