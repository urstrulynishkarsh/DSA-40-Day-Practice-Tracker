#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<numeric>
using namespace std;
bool solve(string &s, string &t,int i, int j,vector<vector<int> > &dp)
{
   if(i>=s.length() && j>=t.length())
   {
        return true;
   }
   if(j>=t.length())
   {
        return false;
   }
   if(dp[i][j]!=-1)
   {
        return dp[i][j];
   }
   bool ans=false;
   if(t[j]=='*')
   {
        ans=solve(s,t,i,j+1,dp)||(i<s.length() && solve(s,t,i+1,j,dp));
   }
   else if(i<s.length() && (s[i]==t[j]||t[j]=='?'))
   {
        ans=solve(s,t,i+1,j+1,dp);
   }
   return dp[i][j]=ans;
}
bool LCS(string &s, string &t)
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