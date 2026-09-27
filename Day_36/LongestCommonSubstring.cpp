#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<numeric>
using namespace std;
int LCS(string& s1, string& s2, int i, int j,vector<vector<int> >&dp)
    {
        if(i==s1.length()||j==s2.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s1[i]==s2[j])
        {
            return dp[i][j]=1+LCS(s1,s2,i+1,j+1,dp);
        }
    }
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int n=s1.length();
        int m=s2.length();
        vector<vector<int> >dp(n+1,vector<int>(m+1,-1));
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxi=max(maxi,LCS(s1,s2,i,j,dp));
            }
        }
        return maxi;
    }
int main()
{
    string str1;
    cout<<"Enter the first string: ";
    getline(cin,str1);
    string str2;
    cout<<"Enter the second string: ";
    getline(cin,str2);

    cout<<longCommSubstr(str1,str2);



}