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

void BottomView(node* root)
{
    if(!root)
    {
        return;
    }
    map<int,int>mp;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while (!q.empty())
    {
        node* t = q.front().first;
        int h = q.front().second;
        q.pop();
        mp[h] = t->data;
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
    BottomView(root);
    return 0;
}


/*

1
2
4
-1
-1
5
-1
-1
3
6
-1
-1
7
-1
-1
4 2 6 3 7 

*/