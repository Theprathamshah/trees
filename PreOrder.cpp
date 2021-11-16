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

vector<int> PostOrder(node *root)
{
    vector<int> ans;
    stack<node *> st;
    while (!st.empty() or root)
    {
        while (root)
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

vector<int> Preorder(node *root)
{
    vector<int> ans;
    stack<node *> st;
    // st.push(root);
    while (!st.empty() or root)
    {
        while (root)
        {
            /* code */
            ans.push_back(root->data);
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        // root = st.top();
        root = root->right;
    }
    return ans;
}

int sum(node* root)
{
    if(!root)
    {
        return 0;
    }
    return sum(root->left) + sum(root->right)  + root->data;
}

int MaxEle(node* root)
{
    if(!root)
    {
        return INT_MIN;
    }
    int a = MaxEle(root->right);
    int b = MaxEle(root->right);
    return max(a,max(b,root->data));
}

void PostOrder2(node *root)
{
    if (!root)
    {
        return;
    }
    PostOrder2(root->left);
    PostOrder2(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = CreateTree();
    vector<int> a = Preorder(root);
    for (auto ele : a)
    {
        cout << ele << " ";
    }
    cout << endl;
    a.clear();
    a = PostOrder(root);
    for (auto ele : a)
    {
        cout << ele << " ";
    }
    cout << endl;
    PostOrder2(root);
    cout<<endl;
    cout<<"Sum of all elements is : "<<sum(root)<<endl;
    cout<<"Max element is : "<<MaxEle(root)<<endl;
    return 0;
}
