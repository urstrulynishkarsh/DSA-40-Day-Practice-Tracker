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
        return s.length()-i;
    }
    if(i==s.length() )
    {
        return t.length()-j;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s[i]==t[j])
    {
        return dp[i][j]=solve(s,t,i+1,j+1,dp);
    }
    else{
        int insertion=1+solve(s,t,i+1,j,dp);
        int deletion=1+solve(s,t,i,j+1,dp);
        int updation=1+solve(s,t,i+1,j+1,dp);
        return dp[i][j]=min({insertion,deletion,updation});
    }
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