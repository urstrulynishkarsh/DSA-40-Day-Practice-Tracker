#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<numeric>
using namespace std;

int solve(int W, vector<int> &val, vector<int> &wt, int index,vector<vector<int>> &dp)
{
    if(index==0)
    {
        if(wt[0]<=W)
        {
            return val[0];
        }
        else{
            return 0;
        }
    }
    if(dp[index][W]!=-1)
    {
        return dp[index][W];
    }

    int exclusion=0+solve(W,val,wt,index-1,dp);
    int inclusion=0;
    if(wt[index]<=W)
    {
        inclusion=val[index]+solve(W-wt[index],val,wt,index-1,dp);
    }
    return dp[index][W]=max(inclusion,exclusion);
}
int knapsack(int &W, vector<int> &val, vector<int> &wt)
{
    int index=val.size()-1;
    vector<vector<int>>dp(index+1,vector<int> (W+1,-1));
    return solve(W,val,wt,index,dp);
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;


    vector<int> val(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }

    vector<int> wt(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    int W;
    cout<<"Enter the W value: ";
    cin>>W;
    cout<<knapsack(W,val,wt);
    
    return 0;
}