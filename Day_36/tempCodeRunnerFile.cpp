#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<numeric>
using namespace std;
int solve(vector<int>& nums, int amount,vector<int>  &dp )
{
    if(amount==0)
    {
        return 1;
    }
    if(amount<0)
    {
        return INT_MAX;
    }
    if(dp[amount]!=-1)
    {
        return dp[amount];
    }
    int mini=INT_MAX;
    for(int i=0;i<nums.size();i++)
    {
        int ans=solve(nums,amount-nums[i],dp);
        if(ans!=INT_MAX)
        {
            mini=min(mini,ans+1);
        }
    }
    return dp[amount]=mini;
}
    int coinchange(vector<int>& nums, int &amount) {
        int n=nums.size();
        vector<int> dp(amount+1,-1);
        int ans=solve(nums,amount,dp);
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
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