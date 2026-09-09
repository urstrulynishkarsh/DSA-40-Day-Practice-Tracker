#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<climits>
#include<algorithm>
using namespace std;

int solve(vector<vector<int> >grid, int r1,int c1, int r2,int c2,vector<vector<vector<vector<int>>>> &dp)
{
    if(r1<0||r2<0||c1<0||c2<0||r1>=grid.size()||r2>=grid.size()||c1>=grid[0].size()||c2>=grid[0].size()||r1!=r2)
    {
        return INT_MIN;
    }
    if(dp[r1][c1][r2][c2]!=-1)
    {
        return dp[r1][c1][r2][c2];
    }
    if(r1==grid.size()-1)
    {
        if(c1==c2)
        {
            return grid[r1][c1];
        }
        return grid[r1][c1]+grid[r2][c2];
    }
    int cheeries=0;
    if(c1==c2)
    {
        cheeries+=grid[r1][c1];
    }
    else{
        cheeries+=grid[r1][c1]+grid[r2][c2];
    }
    int maxi=0;
    for(int dc1=-1;dc1<=1;dc1++)
    {
        for(int dc2=-1;dc2<=1;dc2++)
        {
            maxi=max(maxi,solve(grid,r1+1,c1+dc1,r2+1,c2+dc2,dp));
        }
    }
    return dp[r1][c1][r2][c2]=cheeries+maxi;

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
    vector<vector<vector<vector<int>>>> dp(n+1,
    vector<vector<vector<int>>>(
        m+1,
        vector<vector<int>>(
            n+1,
            vector<int>(m+1, -1)
        )));
    
    int ans=solve(matrix,0,0,0,m-1,dp);
    if(ans<=0)
    {
        cout<<0;
        return 0;
    }
    cout<<ans;
    return 0;
}