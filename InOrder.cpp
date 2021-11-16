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

vector<int> InOrderTraversal(node* root)
{
    stack<node*>st;
    vector<int>ans;
    while (!st.empty() or root)
    {
        while(root)
        {
            st.push(root);
            root = root->left;

        }
        root = st.top();
        ans.push_back(root->data);
        st.pop();
        root = root->right;
    }
    return ans;
    

}

int main()
{
    node* root = CreateTree();
    vector<int>ans = InOrderTraversal(root);
    for(auto ele:ans)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
