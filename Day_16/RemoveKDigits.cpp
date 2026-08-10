#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

string removeKdigits(string num, int k) {
        int n=num.length();
        if(n==k)
        {
            return "0";
        }
        stack<int> st;
        for(char ch:num)
        {
            while(!st.empty() && k>0 && st.top()>ch)
            {
                k--;
                st.pop();
            }
            st.push(ch);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.length() && ans[i]=='0')
        {
            i++;
        }
        ans=ans.substr(i);
        if(ans.empty())
        {
            return "0";
        }
        return ans;
        
    }

int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<removeKdigits(str,k);

}