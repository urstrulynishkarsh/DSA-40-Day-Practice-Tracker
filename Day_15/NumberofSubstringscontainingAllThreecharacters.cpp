#include<iostream>
#include<vector>
using namespace std;

int numberofSubstring(string &s)
{
        int i=0;
        int j=0;
        int n=s.length();
        int ans=0;
        unordered_map<char,int> mp;
        while(j<n)
        {
            mp[s[j]]++;
            while(mp.size()==3)
            {
                ans+=n-j;
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
        
}

int main()
{
    string s;
    cout<<"Enter the s string: ";
    getline(cin,s);
    cout<<numberofSubstring(s);
}