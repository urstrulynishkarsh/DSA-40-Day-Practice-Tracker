
#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;



int solve(vector<vector<int>>&obstacleGrid,int i, int j, vector<vector<int> > &dp)
    {
        if(i<0 ||j<0 || i>=obstacleGrid.size()||j>=obstacleGrid[0].size() || obstacleGrid[i][j]==1)
        {
            return 0;
        }
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int right=solve(obstacleGrid,i,j+1,dp);
        int down=solve(obstacleGrid,i+1,j,dp);
        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int> >dp(n+1,vector<int>(m+1,-1));
        return solve(obstacleGrid,0,0,dp);
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
    
    cout<<uniquePathsWithObstacles(matrix);
    return 0;
}