#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int solve(vector<int>& arr, int index,int k, vector<vector<int>>&dp)
    {
        if(k<0)
        {
            return 0;
        }
        if(index==arr.size())
        {
            return k==0?1:0;
        }
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        return dp[index][k]=solve(arr,index+1,k,dp)+solve(arr,index+1,k-arr[index],dp);
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
                vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));
                return solve( arr, 0, target,dp);
        
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
    cout<<perfectSum(v,target);
    
    return 0;
}