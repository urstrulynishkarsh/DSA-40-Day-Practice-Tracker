#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> prevsmallerelementIndex(vector<int> &nums)
{
    vector<int> ans(nums.size());
    stack<int> st;
    for(int i=0;i<nums.size();i++)
    {   
        int curr=nums[i];
        while(!st.empty() && nums[st.top()]>=curr)
        {   
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}
vector<int> nextsmallerelementIndex(vector<int> &nums)
{
    vector<int> ans(nums.size());
    stack<int> st;
    for(int i=nums.size()-1;i>=0;i--)
    {   
        int curr=nums[i];
        while(!st.empty() && nums[st.top()]>curr)
        {   
            st.pop();
        }
        ans[i]=st.empty()?nums.size():st.top();
        st.push(i);
    }
    return ans;
}

int sumSubarrayMins(vector<int> &nums)
{
   auto next=nextsmallerelementIndex(nums);
   auto prev=prevsmallerelementIndex(nums);

   long long sum=0;
   const int MOD=1e9+7;

   for(int i=0;i<nums.size();i++)
   {
        int previ=prev[i];
        int nexti=next[i];

        int left=i-previ;
        int right=nexti-i;

        long long nooftimes=(left%MOD*right%MOD)%MOD;
        long long total=(nooftimes*nums[i])%MOD;
        sum=(sum+total)%MOD;
   }
   return sum;
    
}
int main()
{
    int n;
    cout<<"Enter the element in the array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<sumSubarrayMins(v);
   
    return 0;
}