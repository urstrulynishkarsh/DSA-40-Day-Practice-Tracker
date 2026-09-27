#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<numeric>
using namespace std;
int solve(string &s, string &t,int i, int j,vector<vector<int> > &dp)
{
    if(i==s.length() || j==t.length())
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s[i]==t[j])
    {
        return dp[i][j]=1+solve(s,t,i+1,j+1,dp);
    }
    else{
        return dp[i][j]=max(solve(s,t,i+1,j,dp),solve(s,t,i,j+1,dp));
    }
}
void LCS(string &s, string &t)
{
    int n=s.length();
    int m=t.length();
    vector<vector<int> >dp(n+1,vector<int>(m+1,-1));
    solve(s,t,0,0,dp);
    int i=n;
    int j=m;
    string ans;
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1])
        {
            ans.push_back(s[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j])
            {
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}
int main()
{
    string str1;
    cout<<"Enter the first string: ";
    getline(cin,str1);
    string str2;
    cout<<"Enter the second string: ";
    getline(cin,str2);

    LCS(str1,str2);




}