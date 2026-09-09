
#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;


int solve(vector<vector<int>>& grid, int i, int j,int n, int m,vector<vector<int> > &dp)
    {
        if(i<0 ||j<0 ||i>=n|| j>=m)
        {
            return INT_MAX;
        }
        if(i==n-1 && j==m-1)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int right=solve(grid,i,j+1,n,m,dp);
        int down=solve(grid,i+1,j,n,m,dp);
        return dp[i][j]= grid[i][j]+ min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> >dp(n+1,vector<int>(m+1,-1));
        return solve(grid,0,0,n,m,dp);
    }




int main()
{
    int n,m;
    cout<<"Enter the row and col: ";
    cin>>n>>m;
    vector<vector<int> >matrix(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    
    cout<<minPathSum(matrix);
    return 0;
}