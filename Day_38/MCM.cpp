#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<numeric>
using namespace std;


int solve(vector<int> &arr, int i, int j,vector<vector<int>> &dp)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=arr[i-1]*arr[k]*arr[j]+solve(arr,i,k,dp)+solve(arr,k+1,j,dp);
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
int MCM(vector<int> &arr)
{
    int n=arr.size();
        int i=1;
        int j=arr.size()-1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(arr, i, j,dp);
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

    cout<<MCM(v);




}