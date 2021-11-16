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

int MaxEle(node *root)
{
    if (!root)
    {
        return INT_MIN;
    }
    int a = MaxEle(root->left);
    int b = MaxEle(root->right);
    return max(a, max(b, root->data));
}

int MinEle(node *root)
{
    if (!root)
    {
        return INT_MAX;
    }
    int a = MinEle(root->left);
    int b = MinEle(root->right);
    return min(a, min(b, root->data));
}

void LevelOrder(node *root)
{
    if (!root)
    {
        return;
    }
    stack<node *> st;
    st.push(root);
    st.push(NULL);
    while (!st.empty())
    {
        node *n = st.top();
        st.pop();
        if (n)
        {
            cout << n->data << " ";

            if (n->left)
            {
                st.push(n->left);
            }
            if (n->right)
            {
                st.push(n->right);
            }
        }
        if (!st.empty())
        {
            st.push(NULL);
        }
    }
}

int main()
{
    node *root = CreateTree();
    cout << "Maximum element in the tree is : " << MaxEle(root) << endl;
    cout << "Minimum element in the tree is : " << MinEle(root) << endl;
    LevelOrder(root);
    return 0;
}
