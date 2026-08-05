#include<iostream>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string &s, int k)
{

        unordered_map<int, int> mp;
        int i=0;
        int j=0;
        int maxi=0;
        int n=s.length();
        int maxfreq=0;
        while(j<n)
        {
            mp[s[j]]++;
            maxfreq=max(maxfreq,mp[s[j]]);
            while((j-i+1)-maxfreq>k)
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