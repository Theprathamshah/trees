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

void LevelOrder(node* root)
{
    if(!root)
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node* n = q.front();
        q.pop();
        if(n)
        {
            cout<<n->data<<" ";
            if(n->left)
            {
                q.push(n->left);
            }
            if(n->right)
            {
                q.push(n->right);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
    
}

int main()
{
        node* root =CreateTree();
    LevelOrder(root);

    return 0;
}
