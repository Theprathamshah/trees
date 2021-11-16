#include<bits/stdc++.h>
using namespace std;
 

class node
{
public:
int data;
node* left;
node* right;
node(int val)
 {
 data = val;
left = NULL;
right = NULL;
}
};
node* CreateTree()
{
 node* root = NULL;
int data;
cin>>data;
 if(data==-1)
{
return NULL;
}
root = new node(data);
root->left = CreateTree();
root->right = CreateTree();
return root;
}

int DiaMerter(node* root,int &size)
{
    if(!root)
    {
        return 0;
    }

}

int MaxHight(node* root)
{
    if(!root)
    {
        return 0;
    }
    return max(MaxHight(root->left),MaxHight(root->right)) + 1;
}

int main()
{
    node* root = CreateTree();
    cout<<MaxHight(root)<<endl;
    map<int,vector<int>>mp;
   
   
    return 0;
}
