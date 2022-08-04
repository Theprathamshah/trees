#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

node *makeTree()
{
    int data;
    cin >> data;
    if (data == -1)
        return nullptr;
    node *root = new node(data);
    root->left = makeTree();
    root->right = makeTree();
    return root;
}

void printPreorder(node *root)
{
    if (!root)
        return;
    printPreorder(root->left);
    printPreorder(root->right);
    cout << root->data << " ";
}

void printPostorder(node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    printPostorder(root->left);
    printPostorder(root->right);
}

void printInorder(node *root)
{
    if (!root)
        return;
    printInorder(root->left);

    cout << root->data << " ";
    printInorder(root->right);
}

node *BSTFromPreorder(int &idx, int pre, vector<int> arr)
{
    if (idx >= arr.size() or arr[idx] >= pre)
        return nullptr;
    node *root = new node(arr[idx]);
    idx++;
    root->left = BSTFromPreorder(idx, root->data, arr);
    root->right = BSTFromPreorder(idx, pre, arr);
    return root;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    int idx = 0;
    node *root = BSTFromPreorder(idx, INT_MAX, arr);
    printPreorder(root);
    cout << endl;
    printInorder(root);
    return 0;
}