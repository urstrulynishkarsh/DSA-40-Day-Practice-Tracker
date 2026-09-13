#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int solve(vector<int>& prices,int index, int buy,int limit,vector<vector<vector<int>>> &dp)
    {
        if(index==prices.size())
        {
            return 0;
        }
        if(limit==0)
        {
            return 0;
        }
        if(dp[index][buy][limit]!=-1)
        {
            return dp[index][buy][limit];
        }
        int profit=0;
        if(buy)
        {
            int buykaro=-prices[index]+solve(prices,index+1,0,limit,dp);
            int skipkaro=0+solve(prices,index+1,1,limit,dp);
            profit+=max(buykaro,skipkaro);
        }
        else{
            int sellkaro=prices[index]+solve(prices,index+1,1,limit-1,dp);
            int skipkaro=0+solve(prices,index+1,0,limit,dp);
            profit+=max(sellkaro,skipkaro);
        }
        return dp[index][buy][limit]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices,0,1,2,dp);
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
    
    cout<<maxProfit(v);
    
    return 0;
}