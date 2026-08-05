#include<iostream>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string &s, int k)
{
    if(k==0)
    {
        return 0;
    }
    int i=0,j=0,maxi=0;
    int n=s.length();
    unordered_map<int,int> mp;
    while(j<n)
    {
        mp[s[j]]++;
        while(mp.size()>k)
        {
            mp[s[i]]--;
            if(mp[s[i]]==0)
            {
                mp.erase(s[i]);
            }
            i++;
        }
        maxi=max(maxi,j-i+1);
        j++;
    }
    return maxi;
}

int main()
{
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);
    int k;
    cout<<"Enter the k  value: ";
    cin>>k;

    cout<<lengthOfLongestSubstring(s,k);
}