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

void DisplayLeftView(node *root)
{
    if (!root)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            node *t = q.front();
            q.pop();
            if (i == 1)
            {
                cout << t->data << " ";
            }
            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
        }

        /* code */
    }
}
void DisplayRightView(node *root)
{
    if (!root)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            node *t = q.front();
            q.pop();
            if (i == n)
            {
                cout << t->data << " ";
            }
            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
        }

        /* code */
    }
}

vector<int> rightView(node *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int p = q.size();
        for (int i = 1; i <= p; i++)
        {
            node *n = q.front();
            q.pop();
            if(i==p)
            {
                ans.push_back(n->data);

            }
            if(n->left)
            {
                q.push(n->left);
            }
            if(n->right)
            {
                q.push(n->right);
            }
            /* code */
        }
    }
    return ans;
}

int main()
{
    node *root = CreateTree();
    cout << "Left View of binary tree is given below" << endl;
    DisplayLeftView(root);
    cout << endl;
    cout << "Right view of binary tree is given below" << endl;
    DisplayRightView(root);
    cout<<endl;
    cout << "Right view of binary tree is given below" << endl;
   vector<int>ans = rightView(root);
   for(auto ele:ans)
   {
       cout<<ele<<" ";
   }
   cout<<endl;
    return 0;
}
