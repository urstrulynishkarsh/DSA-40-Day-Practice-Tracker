#include<iostream>
#include<vector>
using namespace std;


int climibingStairs(int n,vector<int> &dp)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    dp[0]=1;
    dp[1]=1;
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=climibingStairs(n-1,dp)+climibingStairs(n-2,dp);
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<climibingStairs(n,dp);
    
}