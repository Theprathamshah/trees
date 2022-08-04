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
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(node *root)
{
    if (!root)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

void printInorder(node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

node *f(vector<int> &post, unordered_map<int, int> &map, int &postIndex, int start, int end)
{
    if (start > end)
        return nullptr;
    node *root = new node(post[postIndex]);
    int curr = map[post[postIndex]];
    postIndex--;
    root->right = f(post, map, postIndex, curr + 1, end);
    root->left = f(post, map, postIndex, start, curr - 1);
    return root;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> post(n), in(n);
    for (auto &i : post)
        cin >> i;
    for (auto &i : in)
        cin >> i;
    int postIndex = n - 1;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[in[i]] = i;
    }

    node *root = f(post, map, postIndex, 0, n - 1);
    printPreorder(root);
    cout << endl;
    printInorder(root);
    cout << endl;
    printPostorder(root);
    cout << endl;
    return 0;
}

/*

7
4 5 2 6 7 3 1
4 2 5 1 6 3 7

*/