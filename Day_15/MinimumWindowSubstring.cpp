#include<iostream>
#include<vector>
using namespace std;

string minimumWindowSubstring(string &s, string &t)
{
    unordered_map<char, int> mp;
    for(char &ch:t)
    {
        mp[ch]++;
    }
    int i=0;
    int j=0;
    int start=0;
    int minlength=INT_MAX;
    int count=mp.size();
    int n=s.length();
    while(j<n)
    {
        if(mp.find(s[j])!=mp.end())
        {
            mp[s[j]]--;
            if(mp[s[j]]==0)
            {
                count--;
            }
        }
        if(count==0)
        {
            while(count==0)
            {
                if(mp.find(s[i])!=mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                    {
                        count++;
                        if(j-i+1<minlength)
                        {
                            minlength=j-i+1;
                            start=i;
                        }
                    }
                }
                i++;
            }
        }
        j++;
    }
    if(minlength==INT_MAX)
    {
        return "";
    }

    return s.substr(start,minlength);
        
}

int main()
{
    string s;
    cout<<"Enter the s string: ";
    getline(cin,s);
    string t;
    cout<<"Enter the t string: ";
    getline(cin,t);


    cout<<minimumWindowSubstring(s,t);
}