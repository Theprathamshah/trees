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

void solution(vector<int> &ans, node *root)
{
    if (!root)
        return;
    if (!root->left and !root->right)
        return;
    if (root->left and root->right)
    {
        solution(ans, root->right);
        solution(ans, root->left);
    }
    if (!root->left)
    {
        ans.push_back(root->right->data);
        solution(ans, root->right);
    }
    if (!root->right)
    {
        ans.push_back(root->left->data);
        solution(ans, root->left);
    }
    return;
}

void Nosiblings(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        auto rem = q.front();
        q.pop();
        if (!rem->left and rem->right)
        {
            cout << rem->right->data << " ";
            q.push(rem->right);
        }
        else if (!rem->right and rem->left)
        {
            cout << rem->left->data << " ";
            q.push(rem->left);
        }
        else
        {
            if (rem->left and rem->right)
            {
                q.push(rem->left);
                q.push(rem->right);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    node *root = makeTree();
    vector<int> ans;
    solution(ans, root);
    for (auto ele : ans)
        cout << ele << " ";
    cout << endl;
    Nosiblings(root);
    return 0;
}

/*

         1
      2     3
    4         7


    */

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

/*
1
2
4
-1
-1
-1
3
-1
7
-1
-1
*/
