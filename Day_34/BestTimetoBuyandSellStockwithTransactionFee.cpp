#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;
 int solve(vector<int>& prices, int index, int buy, int &fee,vector<vector<int> > &dp)
    {
        if(index==prices.size())
        {
            return 0;
        }
        if(dp[index][buy]!=-1)
        {
            return dp[index][buy];
        }
        int profit=0;
        if(buy)
        {
            int buykaro=-prices[index]+solve(prices,index+1,0,fee,dp);
            int skipkaro=solve(prices,index+1,1,fee,dp);
            profit+=max(buykaro,skipkaro);
        }
        else{   
            int sellkaro=prices[index]-fee+solve(prices,index+1,1,fee,dp);
            int skipkaro=solve(prices,index+1,0,fee,dp);
            profit+=max(sellkaro,skipkaro);
        }

        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int> >dp(n+1,vector<int>(2,-1));
        return solve(prices,0,1,fee,dp);
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
    int fee;
    cout<<"Enter the k value: ";
    cin>>fee;
    cout<<maxProfit(v,fee);
    
    return 0;
}