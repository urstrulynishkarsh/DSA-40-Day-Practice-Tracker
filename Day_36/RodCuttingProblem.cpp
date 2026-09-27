#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<numeric>
using namespace std;


int solve(int W, int n,vector<int> &wt,vector<int> &val,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(wt[0]<=W)
            {
                return val[0];
            }
            return 0;
        }
        if(dp[n][W]!=-1)
        {
            return dp[n][W];
        }
        int skip=0+solve(W,n-1,wt,val,dp);
        int take=0;
        if(wt[n-1]<=W)
        {
            take=val[n-1]+solve(W-wt[n-1],n,wt,val,dp);
        }
        return dp[n][W]=max(skip,take);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<int> length(n,0);
        for(int i=0;i<n;i++)
        {
            length[i]=i+1;
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n,n,length,price,dp);
        
    }

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;


    vector<int> v(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout<<cutRod(v);
}