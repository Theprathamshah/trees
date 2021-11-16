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

void DisplayInOrder(node* root)
{
    if(!root)
    {
        return;
    }
    DisplayInOrder(root->left);
    cout<<root->data<<" ";
    DisplayInOrder(root->right);
}

int TotalNodes(node* root)
{
    if(!root)
    {
        return 0;
    }
    return TotalNodes(root->left) + TotalNodes(root->right) +1;
}

int SumOfDataOFNodes(node* root)
{
    if(!root)
    {
        return 0;
    }
    return SumOfDataOFNodes(root->left) + SumOfDataOFNodes(root->right) + root->data;
}

int main()
{
    node* root = CreateTree();
    DisplayInOrder(root);
    cout<<endl;
    cout<<"Total number of roots in the tree is : "<<TotalNodes(root)<<endl;
    cout<<"Sum of all elements of the tree is : "<<SumOfDataOFNodes(root)<<endl;
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
4 2 5 1 6 3 7 
Total number of roots in the tree is : 7
Sum of all elements of the tree is : 28

*/

