
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

node* createBST(int arr[],int l,int r)
{
    if(l>r)
    {
        return NULL;
    }

    int mid = (l+r)/2;
    node* root = new node(arr[mid]);
    root->left = createBST(arr,l,mid-1);
    root->right = createBST(arr,mid+1,r);
    return root;
}


void printInorder(node*root)
{
    if(!root)
    {
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPreorder(node*root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    node* root = createBST(arr,0,n-1);
    printInorder(root);
    cout<<endl;
    printPreorder(root);
    return 0;
}
