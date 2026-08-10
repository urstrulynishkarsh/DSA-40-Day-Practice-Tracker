#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> prevsmallerelementIndex(vector<int> &arr)
    {
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++)
        {
            int curr=arr[i];
            while(!st.empty() && arr[st.top()]>=curr)
            {
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
     vector<int> nextsmallerelementIndex(vector<int> &arr)
    {
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--)
        {
            int curr=arr[i];
            while(!st.empty() && arr[st.top()]>curr)
            {
                st.pop();
            }
           ans[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevGreaterElementIndex(vector<int>& arr)
    {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int curr=arr[i];
            while(!st.empty() && arr[st.top()]<=curr)
            {
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }


    vector<int> nextgreaterelementIndex(vector<int> &arr)
    {
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--)
        {
            int curr=arr[i];
            while(!st.empty() && arr[st.top()]<curr)
            {
                st.pop();
            }
           ans[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumofMinimumSubArray(vector<int> &nums)
    {
        int n=nums.size();
        auto prev=prevsmallerelementIndex(nums);
        auto next=nextsmallerelementIndex(nums);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans += 1LL * nums[i] * left * right;
        }

        return ans;
    }


    long long sumofMaximumSubArray(vector<int> &nums)
    {
        int n=nums.size();
        auto prev=prevGreaterElementIndex(nums);
        auto next=nextgreaterelementIndex(nums);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans += 1LL * nums[i] * left * right;
        }

        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        auto sumofMaximum=sumofMaximumSubArray(nums);
        auto sumofminimum=sumofMinimumSubArray(nums);
        return  sumofMaximum-sumofminimum;
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
    cout<<subArrayRanges(v);
   
    return 0;
}