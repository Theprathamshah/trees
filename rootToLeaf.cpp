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

void rootToLeafSum(node *root, int s, string path, int low, int high)
{
    if (!root)
    {
        return;
    }
    if (!root->left and !root->right)
    {
        s += root->data;
        if (s >= low and s <= high)
        {
            cout << path << to_string(root->data) << endl;
        }
        return;
    }
    rootToLeafSum(root->left,s+root->data,path+to_string(root->data)+" ",low,high);
    rootToLeafSum(root->right,s+root->data,path+to_string(root->data)+" ",low,high);
    
}

int main()
{
    node *root = CreateTree();
    rootToLeafSum(root,0,"",3,12);
    return 0;
}
