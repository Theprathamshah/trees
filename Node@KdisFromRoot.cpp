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

void nodesAtKDistance(node* root,vector<int>&a,int k,int dis)
{
    if(!root)
    {
        return;
    }
    if(dis==k)
    {
        a.push_back(root->data);
    }
    nodesAtKDistance(root->left,a,k,dis+1);
    nodesAtKDistance(root->right,a,k,dis+1);
}

int main()
{
    node* root = CreateTree();
    vector<int>ans;
    int k;
    cin>>k;
    nodesAtKDistance(root,ans,k,0);
    for(auto ele:ans)
    {
        cout<<ele<<" ";
    }
    return 0;
}
