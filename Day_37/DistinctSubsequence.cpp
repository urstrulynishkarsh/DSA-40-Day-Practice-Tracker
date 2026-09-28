#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<numeric>
using namespace std;
int solve(string &s, string &t,int i, int j,vector<vector<int> > &dp)
{
    if(j==t.length())
    {
        return 1;
    }
    if(i==s.length())
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int skip=solve(s,t,i+1,j,dp);
    int take=0;
    if(s[i]==t[j])
    {
        take=solve(s,t,i+1,j+1,dp);
    }
    return dp[i][j]=skip+take;
    
}
int LCS(string &s, string &t)
{
    int n=s.length();
    int m=t.length();
    vector<vector<int> >dp(n+1,vector<int>(m+1,-1));
    return solve(s,t,0,0,dp);
}
int main()
{
    string str1;
    cout<<"Enter the first string: ";
    getline(cin,str1);
    string str2;
    cout<<"Enter the second string: ";
    getline(cin,str2);

    cout<<LCS(str1,str2);




}