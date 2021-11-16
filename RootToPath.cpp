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

void PathSum(node* root,int s,vector<int>&sum)
{
    if(!root)
    {
        return;
    }
    
    s+= root->data;
    if(!root->left && !root->right)
    {
        sum.push_back(s);
    }
    if(root->left)
    {
        PathSum(root->left,s,sum);
    }
    if(root->right)
    {
        PathSum(root->right,s,sum);
    }
   
}
vector<int> RootToLeaf(node* root)
{
    vector<int>ans;
     PathSum(root,0,ans);
    return ans;
}
bool IsPresent(node* root,int key)
{
    vector<int >a;
    PathSum(root,0,a);
    if(find(a.begin(),a.end(),key)!=a.end())
    {
        return true;
    }
    return false;
}

int main()
{
    node* root = CreateTree();
  vector<int>ans = RootToLeaf(root);
  for(auto ele:ans)
  {
      cout<<ele<<" ";
  }

    return 0;
}
