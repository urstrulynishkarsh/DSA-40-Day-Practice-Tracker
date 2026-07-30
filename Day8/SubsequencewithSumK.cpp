#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

bool check(vector<int> &v, int n, int target, int i, int sum,vector<vector<int> > &dp )
{
    if(sum==target)
    {
        return true;
    }
    if(sum>target || i==n)
    {
        return false;
    }
    if(dp[i][sum]!=-1)
    {
        return dp[i][sum];
    }
    bool nottake=check(v,n, target,i+1, sum,dp);
    bool take=check(v,n,target,i+1,sum+v[i],dp);
    return dp[i][sum]=nottake||take;
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
    int target;
    cout<<"Enter the target value: ";
    cin>>target;
    vector<vector<int> >dp(n+1,vector<int> (target+1,-1));
    cout<<check(v,n,target,0,0,dp);
    
    return 0;
}