#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int houseRobber(vector<int> &nums,int index,int end,vector<int> &dp)
{
    if(index>=end)
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int inclusion=nums[index]+houseRobber(nums,index+2,end,dp);
    int exclusion=houseRobber(nums,index+1,end,dp);
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
    if(n==1)
    {
        cout<<v[0];
        return 0;
    }
    if(n==2)
    {
        cout<<max(v[0],v[1]);
        return 0;
    }
    vector<int> dp1(n+1,-1);
    vector<int> dp2(n+1,-1);

    int ans1=houseRobber(v,0,n-1,dp1);
    int ans2=houseRobber(v,1,n,dp2);
    cout<<max(ans1,ans2);
    
    return 0;
}