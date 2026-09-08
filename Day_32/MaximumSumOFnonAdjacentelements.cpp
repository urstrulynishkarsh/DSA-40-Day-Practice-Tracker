#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int maximumsumNonAdjacent(vector<int> &nums,int index,vector<int> &dp)
{
    if(index>=nums.size())
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int inclusion=nums[index]+maximumsumNonAdjacent(nums,index+2,dp);
    int exclusion=maximumsumNonAdjacent(nums,index+1,dp);
    return dp[index]= max(inclusion,exclusion);
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
    vector<int> dp(n+1,-1);
    cout<<maximumsumNonAdjacent(v,0,dp);
    
    return 0;
}