#include <bits/stdc++.h>
using namespace std;

void PrintKnight(vector<vector<int>>a)
{
    for(auto ele:a)
    {
        for(auto i:ele)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void KnightTour(vector<vector<int>>&a,int n,int x,int y,int move)
{
    if(x>=n or y>=n or x<0 or y<0 or a[x][y]>0)
    {
        return;
    }
    if(x==n*n and y==n*n)
    {
        a[x][y] = move;
        PrintKnight(a);
        a[x][y] = 0;
        return;
    }
    a[x][y] = move;
    KnightTour(a,n,x-2,y+1,move+1);
    KnightTour(a,n,x-1,y+2,move+1);
    KnightTour(a,n,x+1,y+2,move+1);
    KnightTour(a,n,x+2,y+1,move+1);
    KnightTour(a,n,x-2,y-1,move+1);
    KnightTour(a,n,x-1,y-2,move+1);
    KnightTour(a,n,x+1,y-2,move+1);
    KnightTour(a,n,x+2,y-1,move+1);
    a[x][y] = 0;
}

int main()
{
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    vector<vector<int>>a(n,vector<int>(n,0));
    PrintKnight(a);
    cout<<endl;
    
    KnightTour(a,n,x,y,1);
    return 0;
}
