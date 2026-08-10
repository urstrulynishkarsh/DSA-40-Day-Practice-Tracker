#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> asteroideCollide(vector<int> &nums)
{
    int n=nums.size();
    stack<int> st;
    for(int &a:nums)
    {
        while(!st.empty() && st.top()>0 && a<0)
        {
            int sum=a+st.top();
            if(sum<0)
            {
                st.pop();
            }
            else if(sum>0)
            {
                a=0;
            }
            else{
                st.pop();
                a=0;
            }
        }
        if(a!=0)
        {
            st.push(a);
        }
    }
    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();

    }
    reverse(ans.begin(),ans.end());
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
    vector<int> result=asteroideCollide(v);
    for(auto val:result)
    {
        cout<<val<<" ";
    }
    return 0;
}