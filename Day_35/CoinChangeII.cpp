#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<numeric>
using namespace std;
int solve(vector<int>& nums, int n, int amount,vector<vector<int> > &dp )
{
    if(amount==0)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    if(dp[n][amount]!=-1)
    {
        return dp[n][amount];
    }
    int skip=solve(nums,n-1,amount,dp);
    int take=0;
    if(nums[n-1]<=amount)
    {
        take=solve(nums,n,amount-nums[n-1],dp);
    }
    return dp[n][amount]=skip+take;
}
    int coinchange(vector<int>& nums, int &amount) {
        int n=nums.size();
        vector<vector<int> >dp(n+1,vector<int>(amount+1,-1));
        return solve(nums,n,amount,dp);
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
    int amount;
    cout<<"Enter the amount value: ";
    cin>>amount;
    cout<<coinchange(v,amount);
    
    return 0;
}