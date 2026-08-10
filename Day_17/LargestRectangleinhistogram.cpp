#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<list>
using namespace std;

vector<int> prevsmallerelementindex(vector<int> &nums)
{
    int n=nums.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++)
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

vector<int> nextsmallerelementindex(vector<int> &nums)
{
    int n=nums.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        int curr=nums[i];

        while(!st.empty() && nums[st.top()]>curr)
        {
            st.pop();
        }
        ans[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return ans;
}



// O(N) time complexity
int largestRectangleInHistogram(vector<int> &nums)
{
    
    auto next=nextsmallerelementindex(nums);
    auto prev=prevsmallerelementindex(nums);
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {   
        int width=next[i]-prev[i]-1;
        int area=width*nums[i];
        maxi=max(maxi,area);
    }
    return maxi;
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
    cout<<largestRectangleInHistogram(v);
    return 0;
}