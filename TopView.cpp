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

void TopView(node* root)
{
    map<int,int>mp;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while (!q.empty())
    {
        node* t = q.front().first;
        int h = q.front().second;
        q.pop();
        if(!mp[h])
        {
            mp[h] = t->data;
        }
        if(t->left)
        {
            q.push({t->left,h-1});
        }
        if(t->right)
        {
            q.push({t->right,h+1});
        }
    }
    for(auto ele:mp)
    {
        cout<<ele.second<<" ";
    }
}

int main()
{
    node* root = CreateTree();
    TopView(root);
    return 0;
}
