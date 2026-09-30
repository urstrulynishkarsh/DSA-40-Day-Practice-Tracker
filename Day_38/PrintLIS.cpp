#include<bits/stdc++.h>
#include<vector>
using namespace std;


int solve(vector<int>& arr, int n, int curr, int prev, vector<vector<int>>&dp)
    {
            if(curr==n)
            {
                return 0;
            }
            if(dp[curr][prev+1]!=-1)
            {
                return dp[curr][prev+1];
            }
            int skip=solve(arr,n,curr+1,prev,dp);
            int take=0;
            if(prev==-1 || arr[curr]>arr[prev])
            {
                take=1+solve(arr,n,curr+1,curr,dp);
            }
            return dp[curr][prev+1]=max(skip,take);

        }
 vector<int> getLIS(vector<int>& arr)
{
   int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        solve(arr,n,0,-1,dp);
    vector<int> ans;
    int curr=0;
    int prev=-1;
    while(curr<n)
    {
        int skip=solve(arr,n,curr+1,prev,dp);
        int take=0;
        bool cantake=false;
        if(prev==-1 || arr[curr]>arr[prev])
        {
            cantake=true;
            take=1+solve(arr,n,curr+1,curr,dp);
        }
        if(cantake && take>=skip)
        {
            ans.push_back(arr[curr]);
            prev=curr;
        }
        curr++;
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

    vector<int> ans=getLIS(v);
    for(int val:ans)
    {
        cout<<val<<" ";
    }




}