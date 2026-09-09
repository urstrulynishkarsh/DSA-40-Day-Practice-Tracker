#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int triangle(vector<vector<int>> &grid)
{
    int n=grid.size();
    vector<vector<int> > dp=grid;
    for(int row=n-2;row>=0;row--)
    {
        for(int col=0;col<=row;col++)
        {
            dp[row][col]=dp[row][col]+min(dp[row+1][col],dp[row+1][col+1]);
        }
    }
    return dp[0][0];
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
    
    cout<<triangle(matrix);
    return 0;
}