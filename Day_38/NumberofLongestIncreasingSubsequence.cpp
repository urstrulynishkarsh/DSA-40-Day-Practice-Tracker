#include<bits/stdc++.h>
#include<vector>
using namespace std;


pair<int,int> solve(vector<int> &arr,int n, int curr, int prev,vector<vector<pair<int,int>>> &dp)
    {
        if(curr==n)
        {
            return {0,1};
        }
        if(dp[curr][prev+1].first!=-1)
        {
            return dp[curr][prev+1];
        }
        pair<int,int> skip=solve(arr,n,curr+1,prev,dp);
        pair<int,int> take={0,0};
        if(prev==-1 || arr[curr]>arr[prev])
        {
            pair<int,int> temp=solve(arr,n,curr+1,curr,dp);
            take.first=1+temp.first;
            take.second=temp.second;
        }
        pair<int,int> ans;
        if(take.first>skip.first)
        {
            ans=take;
        }
        else if(take.first<skip.first)
        {
            ans=skip;
        }
        else{
            ans.first=take.first;
            ans.second=take.second+skip.second;
        }
        return dp[curr][prev+1]=ans;
        
    }
int LIS(vector<int> &arr)
{
    int n=arr.size();
    vector<vector<pair<int,int>>> dp(
    n + 1,
    vector<pair<int,int>>(n + 1, make_pair(-1, -1))
);
    pair<int,int> ans= solve(arr,n, 0, -1,dp);
    return ans.second;
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

    cout<<LIS(v);




}