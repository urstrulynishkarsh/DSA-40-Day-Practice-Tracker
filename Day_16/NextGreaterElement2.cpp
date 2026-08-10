#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreater(vector<int> &nums)
{
    int n=nums.size();
    if(n==0)
    {
        return {};
    }
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=2*n-1;i>=0;i--)
    {
        int curr=nums[i%n];
        while(!st.empty() && st.top()<=curr)
        {
            st.pop();
        }
        if(i<n)
        {
            ans[i]=st.empty()?-1:st.top();
        }
        st.push(curr);
    }
    return ans;
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
    vector<int> result=nextGreater(v);
    for(auto val:result)
    {
        cout<<val<<" ";
    }
    return 0;
}