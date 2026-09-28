// 1. Max Score Path in a Grid (2D Mtrix.cpp)

// You're given an N × N board. The top-left cell is E (start) and the bottom-right is S (end). Every other cell is a digit 1–9 or x (blocked).

// From any cell you can move right, down, or diagonally down-right, but never onto an x.

// Return two numbers:

// The maximum sum of digits you can collect on a path from E to S.
// The number of paths that achieve that maximum.

// If there is no path, return 0 0.

// Example 1

// Input:
// E 2 3
// 1 x 4
// 5 6 S
// Output: 12 1

// Explanation: The best path is E → 1 → 5 → 6 → S = 12, and only one path gives 12.

// Example 2

// Input:
// E 1 1
// 1 x 1
// 1 1 S
// Output: 3 2

// Explanation: Going along the top-right edge or the bottom-left edge both give 3.

// Input format: T, then for each test: N, followed by N rows.

// Leetcode 1302


#include<bits/stdc++.h>
using namespace std;

pair<int,long long> solve(int i, int j,int N,vector<vector<char>> &grid,vector<vector<int>> dp, vector<vector<long long>> &ways)
{
    if(i<0 ||j<0 ||i>=N ||j>=N)
    {
        return {-1,0};
    }
    if(grid[i][j]=='X')
    {
        return {-1,0};
    }
    if(i==N-1 && j==N-1)
    {
        return {0,1};
    }
    if(dp[i][j]!=-2)
    {
        return {dp[i][j],ways[i][j]};
    }
    pair<int,long long> down=solve(i+1,j,N,grid,dp,ways);
    pair<int,long long> right=solve(i,j+1,N,grid,dp,ways);
    pair<int,long long> diagonal=solve(i+1,j+1,N,grid,dp,ways);

    int best=-1;
    if(right.first!=-1)
    {
        best=max(best,right.first);
    }
    if(down.first!=-1)
    {
        best=max(best,down.first);
    }
    if(diagonal.first!=-1)
    {
        best=max(best,diagonal.first);
    }
    // not path possible
    if(best==-1)
    {
        dp[i][j]=-1;
        ways[i][j]=0;
        return {-1,0};
    }

    long long count=0;
    if(right.first==best)
    {
        count+=right.second;
    }
    if(down.first==best)
    {
        count+=down.second;
    }
    if(diagonal.first==best)
    {
        count+=down.second;
    }
    int value=0;
    if(grid[i][j]>='1'&&grid[i][j]<='9')
    {
        value=grid[i][j]-'0';
    }
    dp[i][j]=value+best;
    ways[i][j]=count;

    return {dp[i][j],ways[i][j]};

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<vector<char>> grid(N,vector<char>(N));

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>grid[i][j];
            }
        }

        vector<vector<int>> dp(N+1,vector<int>(N+1,-2));

        vector<vector<long long>>ways(N+1,vector<long long>(N+1,0));

        pair<int,long long> ans=solve(0,0,N,grid,dp,ways);

        if (ans.first == -1) {
            cout << "0 0\n";
        }
        else {
            cout << ans.first << " "
                 << ans.second << "\n";
        }
    }
    return 0;
}