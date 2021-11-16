#include<bits/stdc++.h>
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

int searchtree(int in[],int s,int e,int key)
{
    for (int i = s; i <=e; i++)
    {
        /* code */
        if(in[i]==key)
        {
            return i;
        }
    }
    return -1;
}

void Inorder(node* &n)
{
    if(!n)
    {
        return;
    }
    
    Inorder(n->left);
    cout<<n->data<<" ";
    Inorder(n->right);
}

node* BuiltTree(int pre[],int in[],int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
   static int idx = 0;
    int curr = pre[idx];
    idx++;
    
    node* n = new node(curr);
    if(s==e)
    {
        return n;
    }
    int pos = searchtree(in,s,e,curr);
   n->left =  BuiltTree(pre,in,s,pos-1);
  n->right =   BuiltTree(pre,in,pos+1,e);
return n;

}

int main()
{
    int pre[] = {1,2,4,3,5};
    int inOr[] = {4,2,1,5,3};
   node* head= BuiltTree(pre,inOr,0,(sizeof(inOr)/sizeof(inOr[0]))-1);
    Inorder(head);
    return 0;
}
