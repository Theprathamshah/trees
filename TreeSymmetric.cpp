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

bool Helper(node *root, node *root1)
{
    if (!root and !root1)
    {
        return true;
    }
    if (root1->data == root->data)
    {
        return (Helper(root->left, root1->right) && Helper(root->right, root1->left));
    }
    return false;
}

bool TreeSymmetric(node *root)
{
    if (!root)
    {
        return true;
    }
    if (Helper(root, root))
    {
        return true;
    }
    return false;
}

void LevelOrder(node *root)
{
    queue<node *> st;
    st.push(root);
    st.push(NULL);
    while (!st.empty())
    {

        node *n = st.front();
        st.pop();
        if (!st.empty() and n)
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

bool TreesAreIdentical(node *r1, node *r2)
{
    if (!r1 and r2)
    {
        return true;
    }
    if (Helper(r1->left, r2->left) and Helper(r2->left, r2->right))
    {
        return true;
    }
    return false;
}



void LeftView(node *root)
{
    if (!root)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty() and root)
    {
        int l = q.size();
        for (int i = 1; i <= l; i++)
        {
            node *t = q.front();
            q.pop();
            if(i==1)
            {
                cout<<t->data<<" ";
            }
            if(t->left)
            {
                q.push(t->left);
            }
            if(t->right)
            {
                q.push(t->right);
            }
        }
    }
}

int main()
{
    node *root1 = CreateTree();
   LeftView(root1);
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