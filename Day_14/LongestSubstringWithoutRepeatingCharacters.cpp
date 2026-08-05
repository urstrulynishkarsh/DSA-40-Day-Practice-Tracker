#include<iostream>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string &s)
{
   
        unordered_map<int, int> mp;
        int i=0;
        int j=0;
        int maxi=0;
        int n=s.length();
        while(j<n)
        {
            mp[s[j]]++;
            while(mp.size()<j-i+1)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            if(mp.size()==j-i+1)
            {
                maxi=max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
}

int main()
{
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);


    cout<<lengthOfLongestSubstring(s);
}