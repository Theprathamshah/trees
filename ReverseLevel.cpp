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

vector<int> ReverseLevel(node* root)
{
    vector<int>ans;
    queue<node*>q;
    q.push(root);
    while (!q.empty())
    {
        node* t = q.front();
        q.pop();
        ans.push_back(t->data);
        if(t->right)
        {
            q.push(t->right);
        }
        if(t->left)
        {
            q.push(t->left);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}

int main()
{
    node* root = CreateTree();
    vector<int>ans = ReverseLevel(root);
    for(auto ele:ans)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
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