#include<iostream>
#include<vector>
using namespace std;

int paths(int i, int j,int m, int n,vector<vector<int> > &dp)
{
    if(i<0 ||i>=m ||j<0 ||j>=n)
    {
        return 0;
    }
    if(i==m-1 && j==n-1)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    int right=paths(i,j+1,m,n,dp);
    int down=paths(i+1,j,m,n,dp);
    return dp[i][j]=right+down;
}
int main()
{
    int m,n;
    cout<<"Enter the value of m and n: ";
    cin>>m>>n;
    vector<vector<int> >dp(m+1,vector<int>(n+1,-1));
    cout<<paths(0,0,m,n,dp);
}