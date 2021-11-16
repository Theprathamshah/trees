
// #include <bits/stdc++.h>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *left;
//     node *right;
//     node(int val)
//     {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// node *CreateTree()
// {
//     node *root = NULL;
//     int data;
//     cin >> data;
//     if (data == -1)
//     {
//         return NULL;
//     }
//     root = new node(data);
//     root->left = CreateTree();
//     root->right = CreateTree();
//     return root;
// }

// bool IsPresent(node *root, int key)
// {
//     if (!root)
//     {
//         return false;
//     }
//     if (root->data == key)
//     {
//         return true;
//     }
//     return (IsPresent(root->left, key) || IsPresent(root->right, key));
// }

// int main()
// {
//     node *root = CreateTree();
//     if(IsPresent(root,4))
//     {
//         cout<<"Element is present in the array"<<endl;
//     }
//     else
//     {
//         cout<<"Element is not present in the array"<<endl;
//     }
//     if(IsPresent(root,1))
//     {
//         cout<<"Element is present in the array"<<endl;
//     }
//     else
//     {
//         cout<<"Element is not present in the array"<<endl;
//     }
//     if(IsPresent(root,45))
//     {
//         cout<<"Element is present in the array"<<endl;
//     }
//     else
//     {
//         cout<<"Element is not present in the array"<<endl;
//     }
//     if(IsPresent(root,8))
//     {
//         cout<<"Element is present in the array"<<endl;
//     }
//     else
//     {
//         cout<<"Element is not present in the array"<<endl;
//     }
//     if(IsPresent(root,7))
//     {
//         cout<<"Element is present in the array"<<endl;
//     }
//     else
//     {
//         cout<<"Element is not present in the array"<<endl;
//     }
//     return 0;
// }
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
Element is present in the array
Element is present in the array
Element is not present in the array
Element is not present in the array
Element is present in the array
*/

// #include <bits/stdc++.h>
// using namespace std;

// int MinimunCost(vector<vector<int>> ans, vector<vector<int>> dp, int n)
// {
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = n - 1; j >= 0; j--)
//         {
//             if (i == n - 1 and j == n - 1)
//             {
//                 dp[i][j] = ans[i][j];
//             }
//             else if (i == n - 1)
//             {
//                 dp[i][j] = ans[i][j] + dp[i][j + 1];
//             }
//             else if (j == n - 1)
//             {
//                 dp[i][j] = ans[i][j] + dp[i + 1][j];
//             }
//             else
//             {
//                 dp[i][j] = ans[i][j] + min(dp[i][j+1],dp[i+1][j]);
//             }
//         }
//     }
//     return dp[0][0];
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> v(n, vector<int>(n));
//     for (auto &i : v)
//     {
//         for (autoq &j : i)
//         {
//             cin >> j;
//         }
//     }
//     vector<vector<int>> dp(n, vector<int>(n));
//     cout<<"Minimum cost to reach to bottom is "<<MinimunCost(v,dp,n)<<endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void FloodFill(vector<vector<int>> &a, int x, int y, int toFill, int prev, int n)
// {
//     if (x >= n or y >= n or x < 0 or y < 0)
//     {
//         return;
//     }
//     if (a[x][y] != prev)
//     {
//         return;
//     }
//     if (a[x][y] == toFill)
//     {
//         return;
//     }
//     a[x][y]=toFill;
//     FloodFill(a,x+1,y,toFill,prev,n);
//     FloodFill(a,x-1,y,toFill,prev,n);
//     FloodFill(a,x,y+1,toFill,prev,n);
//     FloodFill(a,x,y-1,toFill,prev,n);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> a(n, vector<int>(n));
//     for (auto &i : a)
//     {
//         for (auto &j : i)
//         {
//             cin >> j;
//         }
//     }
//     FloodFill(a,0,0,7,1,n);
//     for(auto ele:a)
//     {
//         for(auto i:ele)
//         {
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// vector<string>ans;

// void GeneratePatenthese(string &s,int open,int close)
// {
//     if(!open and !close)
//     {
//         ans.push_back(s);
//     return;
//     }
//     if(open)
//     {
//         s.push_back('(');
//         GeneratePatenthese(s,open-1,close);
//         s.pop_back();
//     }
//     if(open<close and open)
//     {
//         s.push_back(')');
//         GeneratePatenthese(s,open,close-1);
//         s.pop_back();
//     }

// }

// int main()
// {
//     string s= "";
//     GeneratePatenthese(s,3,3);
//     for(auto ele:ans)
//     {
//         cout<<ele<<endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> TwoSum(int n,int arr[],int key)
// {
//     unordered_map<int,int>mp;
//     for (int i = 0; i < n; i++)
//     {
//         int s = key - arr[i];
//         if(mp.find(s)!=mp.end())
//         {
//             return {mp.find(s)->second,i};
//         }
//         mp.insert({arr[i],i});
//     }
//     return {-1};

// }

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int key;
//     cin>>key;
//     vector<int>ans = TwoSum(n,arr,key);
//     if(count(ans.begin(),ans.end(),-1))
//     {
//         cout<<"No pair is present in the array"<<endl;
//         return 0;
//     }
//     for(auto ele:ans)
//     {
//         cout<<ele<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *left;
//     node *right;
//     node(int val)
//     {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// node *CreateTree()
// {
//     node *root = NULL;
//     int data;
//     cin >> data;
//     if (data == -1)
//     {
//         return NULL;
//     }
//     root = new node(data);
//     root->left = CreateTree();
//     root->right = CreateTree();
//     return root;
// }

// bool Helper(node* root1,node* root2)
// {
//     if(!root1 and !root2)
//     {
//         return true;
//     }
//     if(root1->data==root2->data)
//     {
//         return true;
//     }
//     if(root1->data!=root2->data)
//     {
//         return false;
//     }
//     return Helper(root1->left,root2->right);
// }

// bool syemetricTree(node* root)
// {
//     if(Helper(root,root))
//     {
//         return true;
//     }
//     return false;
// }

// bool IsElementPresent(node* root,int key)
// {
//     if(!root)
//     {
//         return false;
//     }
//     if(root->data==key)
//     {
//         return true;
//     }
//     return (IsElementPresent(root->left,key) | IsElementPresent(root->right,key));
// }

// int main()
// {
//     node* root = CreateTree();
//     if(IsElementPresent(root,7))
//     {
//         cout<<"Element is present in the tree"<<endl;
//     }
//     else
//     {
//         cout<<"element is not present in the tree"<<endl;
//     }
//     if(IsElementPresent(root,735))
//     {
//         cout<<"Element is present in the tree"<<endl;
//     }
//     else
//     {
//         cout<<"element is not present in the tree"<<endl;
//     }
//     if(syemetricTree(root))
//     {
//         cout<<"Tree is symmetric"<<endl;
//     }
//     else
//     {
//         cout<<"Tree is not symmetric"<<endl;
//     }

//     return 0;
// }
/*

1
1 
1 
-1
-1
1
-1
-1
1
1
-1
-1
1
-1
-1
*/

// #include<bits/stdc++.h>
// using namespace std;

// int dpFibonacci(int n,int dp[])
// {
//     if(n==0 or n==1)
//     {
//         return n;
//     }
//     int a = dpFibonacci(n-1,dp) + dpFibonacci(n-2,dp);
//     dp[n] = a;
//     return a;
// }

// int main()
// {
//     int n;
//     cin>>n;
//     cout<<n<<" Fibonacci number is : "<<dpFibonacci(n,new int[n+1])<<endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class A
// {
//     int age;

// public:
//     A()
//     {
//         cout << "Default constructor called" << endl;
//     }
//     A(int a)
//     {
//         cout << "User made constructor called" << endl;
//         age = a;
//     }
//     A(A &obj)
//     {
//         cout << "Copy constructor called!!!!!!!!!!!!" << endl;
//         age = obj.age;
//     }
//     void setdata(int x)
//     {
//         age = x;
//     }
//     int getData()
//     {
//         return age;
//     }
// };

// int main()
// {
//     A a, b;
//     A c(199);
//     a.setdata(100);
//     A d = c;
//     cout << a.getData() << endl;
//     cout << d.getData() << endl;
//     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int k;
//     cin>>k;
//    for (int i = 0; i < n; i++)
//    {
//        int temp = arr[(i+k)%n];
//        arr[i] = temp;

//    }
//    for (int i = 0; i < n; i++)
//    {
//        cout<<arr[i]<<" ";
//    }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// bool Comperator(pair<int,int>p1,pair<int,int>p2)
// {
//     return p1.second<p2.second;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<pair<int, int>> v(n);
//     for (auto &i : v)
//     {
//         cin >> i.first >> i.second;
//     }
//     cout<<"Vector of pairs is given below"<<endl;
//     for (auto ele : v)
//     {
//         cout << ele.first << " " << ele.second << " ";
//         cout << endl;
//     }
//     cout<<"After sorting with respect to first element of pair"<<endl;
//     sort(v.begin(),v.end());
//      for (auto ele : v)
//     {
//         cout << ele.first << " " << ele.second << " ";
//         cout << endl;
//     }

//     cout<<"After sorting with respect to second element of pair"<<endl;
//     sort(v.begin(),v.end(),Comperator);
//      for (auto ele : v)
//     {
//         cout << ele.first << " " << ele.second << " ";
//         cout << endl;
//     }

//     return 0;
// }
/*
5
32 -45  
4 56
0 4
-45 -4
32 6
*/

// #include<bits/stdc++.h>
// using namespace std;

// bool Comperator(pair<int,int>p1,pair<int,int>p2)
// {
//     return p1.second<p2.second;
// }

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int>v(n);
//     for(auto &i:v)
//     {
//         cin>>i;
//     }
//     map<int,int>mp;
//     for (int i = 0; i < n; i++)
//     {
//         mp[v[i]]++;
//     }
//     vector<pair<int,int>>a;
//     for(auto ele:mp)
//     {
//         a.push_back(make_pair(ele.first,ele.second));
//     }
//     sort(a.begin(),a.end(),Comperator);
//     for(auto ele:a)
//     {
//         while(ele.second--)
//         {
//             cout<<ele.first<<" ";
//         }

//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (auto &i : a)
//     {
//         cin >> i;
//     }
//     int N = 1e6 + 2;
//     bool arr[N] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] >=0)
//         {
//             arr[a[i]] = 1;
//         }
//     }
//     for (int i = 0; i < N; i++)
//     {
//         if(arr[i]==0)
//         {
//             cout<<i<<endl;
//             break;
//         }
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int>a(n);
//     for(auto &i:a)
//     {
//         cin>>i;
//     }
//     vector<int>ans;
//     stack<int>st;
//     for (int i = n-1; i >=0; i--)
//     {
//         while (st.top()<a[i])
//         {
//             st.pop();
//         }
//         if(st.top()>a[i])
//         {
//             ans.push_back(a[i]);
//         }
//         if(st.empty())
//         {
//             ans.push_back(-1);
//         }
//         st.push(a[i]);
//     }
//     for(auto ele:ans)
//     {
//         cout<<ele<<" ";
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *left;
//     node *right;
//     node(int val)
//     {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// node *CreateTree()
// {
//     node *root = NULL;
//     int data;
//     cin >> data;
//     if (data == -1)
//     {
//         return NULL;
//     }
//     root = new node(data);
//     root->left = CreateTree();
//     root->right = CreateTree();
//     return root;
// }

// bool SameTree(node* root1,node* root2)
// {
//     if(root1->data == root2->data)
//     {
//         return true;
//     }
//     if(!root1 and !root2)
//     {
//         return true;
//     }
//     if(!root1 or !root2)
//     {
//         return false;
//     }
//     return (root1->data==root2->data and SameTree(root1->left,root2->left) and SameTree(root1->right ,root2->right));

// }

// bool MirrorTree(node* root1,node*root2)
// {
//     if(!root1 and !root2)
//     {
//         return true;
//     }
//     if(!root1 or !root2)
//     {
//         return false;
//     }
//     return (root1->data==root2->data and MirrorTree(root1->left,root2->right) and MirrorTree(root1->right,root2->left));

// }

// int main()
// {
//     cout<<"Enter data for tree 1"<<endl;
//     node* root1 = CreateTree();
//     cout<<"Enter data for tree 2"<<endl;
//     node* root2 = CreateTree();
//     if(SameTree(root1 , root2))
//     {
//         cout<<"Both trees are same"<<endl;
//     }
//     else
//     {
//         cout<<"Both trees are not same"<<endl;
//     }
//     if(MirrorTree(root1 , root2))
//     {
//         cout<<"Both trees are Mirror of each other"<<endl;
//     }
//     else
//     {
//         cout<<"Both trees are not Mirror of each other"<<endl;
//     }
//     return 0;
// }
/*
Enter data for tree 1
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
Enter data for tree 2
1
1
1
-1
-1
1
-1
-1
1
1
-1
-1
1
-1
-1
Both trees are not same
*/

// #include<bits/stdc++.h>
// using namespace std;

// class node
// {
//     public:
//     int data;
//     node* next;
//     node(int val)
//     {
//         data = val;
//         next = NULL;
//     }

// };
// void InsertAtTail(node* &head,int val)
// {

//     node* n  = new node(val);
//     if(!head)
//     {
//         head = n;
//         return;
//     }
//     node* t = head;
//     while (t->next)
//     {
//         t = t->next;
//     }
//     t->next = n;

// }

// void Display(node* head)
// {
//     if(!head)
//     {

//         return;
//     }
//     node* t= head;
//     while (t)
//     {
//         cout<<t->data<<"->";
//         t  =t->next;
//     }
//     cout<<"NULL"<<endl;
// }

// int main()
// {
//    int n;
//    cin>>n;
//    int arr[n];
//    for(int i = 0;i<n;i++)
//     {
//    cin>>arr[i];

//    }
//    node* head =NULL;
//    for (int i = 0; i < n; i++)
//    {
//        InsertAtTail(head,arr[i]);
//    }
//    Display(head);

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int sum(int a,int b)
// {
//     return (a|b) + (a&b);
// }

// int SumUsingBits(int a,int b)
// {
//     while(b)
//     {
//         int carry = a&b;
//         a = a^b;
//         b = carry<<1;
//     }
//     return a;
// }

// int SubtractionusingBits(int a,int b)
// {
//     while(b)
//     {
//         int carry = a&b;
//         a = a^b;
//         b = (a&b)<<1;
//     }
//     return a;
// }

// int main()
// {
//     int a,b;
//     cin>>a>>b;
//     cout<<sum(a,b)<<endl;
//     cout<<SumUsingBits(a,b)<<endl;
//     cout<<SubtractionusingBits(a,b)<<endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// bool comp(tuple<int,int,int>a,tuple<int,int,int>b)
// {
//     return get<1>(a)<get<1>(b);
// }

// bool comp2(tuple<int,int,int>a,tuple<int,int,int>b)
// {
//     return get<2>(a)<get<2>(b);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<tuple<int, int, int>> v;
//     for (int i = 0; i < n; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         v.push_back(make_tuple(a, b, c));
//     }
//     cout << "Basic Vactor of tuple" << endl;
//     for (auto ele : v)
//     {
//         cout << get<0>(ele) << " " << get<1>(ele) << " " << get<2>(ele);
//         cout << endl;
//     }
//     sort(v.begin(),v.end())
//     cout << " Vactor of tuple after sort w.r.t first element" << endl;
//     for (auto ele : v)
//     {
//         cout << get<0>(ele) << " " << get<1>(ele) << " " << get<2>(ele);
//         cout << endl;
//     }
//     sort(v.begin(),v.end(),comp);
//     cout << "Vector of tuple after sort by first element" << endl;
//     for (auto ele : v)
//     {
//         cout << get<0>(ele) << " " << get<1>(ele) << " " << get<2>(ele);
//         cout << endl;
//     }
//     sort(v.begin(),v.end(),comp2);
//     cout << "Vector of tuple after sort W.R.T second element" << endl;
//     for (auto ele : v)
//     {
//         cout << get<0>(ele) << " " << get<1>(ele) << " " << get<2>(ele);
//         cout << endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class square
// {
// public:
//     int length;
//     int area;
// };
// class Rectangle
// {
// public:
//     int length;
//     int width;
//     int area;

//     friend bool Compare(square A, Rectangle B);
// };

// bool Compare(square A, Rectangle B)
// {
//     if (A.area == B.area)
//     {
//         return true;
//     }
//     return false;
// }

// int main()
// {
//     square A;
//     Rectangle B;
//     cout << "Enter the length of the square" << endl;
//     cin >> A.length;
//     cout << "Enter length of side of rectangle" << endl;
//     cin >> B.length;
//     cout << "Enter width of rectangle" << endl;
//     cin >> B.width;

//     A.area = A.length * A.length;
//     B.area = B.length * B.width;
//     if (Compare(A, B))
//     {
//         cout << "Area are same" << endl;
//     }
//     else
//     {
//         cout << "Area are not same" << endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void Reverse(int n, int arr[])
// {
//     int l = 0;
//     int r = n - 1;
//     while (l < r)
//     {
//         swap(arr[l], arr[r]);
//         l++;
//         r--;
//     }
// }

// void RotateAnArray(int n,int arr[])
// {

// }

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     Reverse(n,arr);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i]<<" ";
//     }
//     cout << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int KnapSack(int Weight[], int n, int W, int val[])
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (Weight[n - 1] > W)
//     {
//         return KnapSack(Weight, n - 1, W, val);
//     }
//     return max(KnapSack(Weight, n - 1, W, val), KnapSack(Weight, n - 1, W - Weight[n - 1], val) + val[n - 1]);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int Weight[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> Weight[i];
//     }
//     int val[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> val[i];
//     }
//     int W;
//     cin>>W;
//     cout<<KnapSack(Weight,n,W)<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int KnapSack(vector<int>Weight, int n, int W,vector<int>val)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (Weight[n - 1] > W)
//     {
//         return KnapSack(Weight, n - 1, W, val);
//     }
//     return max(KnapSack(Weight, n - 1, W, val), KnapSack(Weight, n - 1, W - Weight[n - 1], val) + val[n - 1]);
// }

// int main()
// {
//     int n;
//     cin>>n;
//     int W;
//     cin>>W;
//     vector<int>Weight(n);
//     vector<int>val(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin>>Weight[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin>>val[i];
//     }
//     cout<<"Max Profit is : "<<KnapSack(Weight,n,W,val)<<endl;

//     memset

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int KnapSack(int n, int W, vector<int> weight, vector<int> val, vector<vector<int>> dp)
// {

//     if (!n or !W)
//     {
//         return 0;
//     }
//     if (dp[n][W] != -1)
//     {
//         return dp[n][W];
//     }
//     if (weight[n - 1] > W)
//     {
//         dp[n][W] = KnapSack(n - 1, W, weight, val, dp);
//     }
//     return dp[n][W] = max(KnapSack(n - 1, W, weight, val, dp), KnapSack(n - 1, W - weight[n - 1], weight, val, dp) + val[n - 1]);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int W;
//     cin >> W;
//     vector<int> Weight(n);
//     vector<int> val(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> Weight[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> val[i];
//     }
//     vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
//     // memset(dp,-1,sizeof(dp));
//     cout << KnapSack(n, W, Weight, val, dp) << endl;
//     return 0;
// }
/*


    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;

    */
/*

-	-   -	
-	-	30	
-	20  -	
-	20	30	
10	-	-	
10	-	30	
10	20	-	
10	20	30	

*/

// MAKE BINARY SEARCH TREE FROM SORTED ARRAY

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

node* createBST(int arr[],int l,int r)
{
    if(l>r)
    {
        return NULL;
    }

    int mid = (l+r)/2;
    node* root = new node(arr[mid]);
    root->left = createBST(arr,l,mid-1);
    root->right = createBST(arr,mid+1,r);
    return root;
}

void printInorder(node*root)
{
    if(!root)
    {
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPreorder(node*root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    node* root = createBST(arr,0,n-1);
    printInorder(root);
    cout<<endl;
    printPreorder(root);
    return 0;
}
