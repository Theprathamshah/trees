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

bool isLeaf(node *root)
{
    if (!root->right and !root->left)
    {
        return true;
    }
    return false;
}

void addLeftBoundary(node *root, vector<int> &a)
{
    node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            a.push_back(curr->data);
        }
        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void addLeafNodes(node *root, vector<int> &a)
{
    if (isLeaf(root))
    {
        a.push_back(root->data);
        return;
    }
    if (root->left)
    {
        addLeafNodes(root->left, a);
    }
    if (root->right)
    {
        addLeafNodes(root->right, a);
    }
}

void addRightNodes(node *root, vector<int> &a)
{
    node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }
        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    reverse(temp.begin(), temp.end());
    for (auto ele : temp)
    {
        a.push_back(ele);
    }
}

vector<int> inorderTraversal(node *root)
{
    stack<node *> st;
    vector<int> inorder;
    node *curr = root;
    while (true)
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            curr = st.top();
            st.pop();
            inorder.push_back(curr->data);
            curr = curr->right;
        }
    }
    return inorder;
}

vector<int> postorderTraversal(node *root)
{
    node *curr = root;
    node *temp;
    vector<int> postorder;
    stack<node *> st;
    while (curr or !st.empty())
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = st.top()->right;
            if (!temp)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                // temp = temp->right;
                while (!st.empty() and temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return postorder;
}

int main()
{
    node *root = CreateTree();
    vector<int> ans;
    if (!root)
    {
        cout << "Tree doesn't exist" << endl;
    }
    if (!isLeaf(root))
    {
        ans.push_back(root->data);
    }
    addLeftBoundary(root, ans);
    addLeafNodes(root, ans);
    addRightNodes(root, ans);
    cout << "Boundary travesal of tree is given below" << endl;
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
    cout << "Inorder traversal of tree is given below" << endl;
    vector<int> inor = inorderTraversal(root);
    for (auto ele : inor)
    {
        cout << ele << " ";
    }
    cout << endl;
    cout << "postorder traversal of tree is given below" << endl;

    vector<int> postorder = postorderTraversal(root);
    for (auto ele : postorder)
    {
        cout << ele << " ";
    }
    cout << endl;
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