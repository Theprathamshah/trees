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

node* BuildTree()
{
    
    node* root =NULL;
    int data;
    cout<<"Enter Data : "<<endl;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    root = new node(data);
    cout<<"Enter left for : "<<data<<endl;
    root->left = BuildTree();
    cout<<"Enter right for : "<<data<<endl;
    root->right = BuildTree();
    return root;
}

void DisplayInOrder(node* root)
{
    if(!root )
    {
        return;
    }
    DisplayInOrder(root->left);
    cout<<root->data<<" ";
    DisplayInOrder(root->right);
}


int main()
{
   node* root = BuildTree();

    return 0;
}
