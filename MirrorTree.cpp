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

void MTree(node* root)
{
    
}

void MirrorTree(node* root)
{
    if(!root)
    {
        return;
    }
    MirrorTree(root->left);
    MirrorTree(root->right);
    node* t = root->left;
    root->left = root->right;
    root->right = t;
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
    node* root = CreateTree();
    LevelOrder(root);
    cout<<endl;
    MirrorTree(root);
    LevelOrder(root);
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
*/