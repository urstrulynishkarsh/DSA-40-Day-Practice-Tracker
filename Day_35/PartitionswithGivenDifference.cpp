#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<numeric>
using namespace std;

int solve(vector<int>& arr, int index, int sum,vector<vector<int> > &dp )
{
    if(index==arr.size())
    {
        if(sum==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[index][sum]!=-1)
    {
        return dp[index][sum];
    }
    int skip=solve(arr,index+1,sum,dp);
    int take=0;
    if(arr[index]<=sum)
    {
        take=solve(arr,index+1,sum-arr[index],dp);
    }
    return dp[index][sum]=skip+take;
}
int countPartitions(vector<int>& arr, int diff) {
    int n=arr.size();
    int total=accumulate(arr.begin(),arr.end(),0);
   
    int sum=(diff+total)/2;
     if(total+diff<0 || (total+diff)%2!=0)
    {
        return 0;
    }
    vector<vector<int> >dp(n+1,vector<int>(sum+1,-1));
    return  solve(arr,0,sum,dp);

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
    cout<<"Enter the k value: ";
    cin>>target;
    cout<<countPartitions(v,target);
    
    return 0;
}