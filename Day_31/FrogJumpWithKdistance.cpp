#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int frogjump(vector<int> &heights,int k)
{
    int n=heights.size();
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int cost=dp[i-j]+abs(heights[i]-heights[i-j]);
                dp[i]=min(dp[i],cost);
            }
        }
    }
    return dp[n-1];
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
    int k;
    cout<<"Enter the k value: ";
    cin>>k;
    cout<<frogjump(v,k);
    
    return 0;
}