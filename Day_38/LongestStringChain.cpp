#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<numeric>
using namespace std;

bool ispredecessor(string &a, string &b)
{
    if(b.length()!=a.length()+1)
    {
        return false;
    }
    int i=0;
    int j=0;
    while(i<a.length()&&j<b.length())
    {
        if(a[i]==b[j])
        {
            i++;
        }
        j++;
    }
    return i==a.length();
}
int solve(vector<string> &words,int n, int curr, int prev,vector<vector<int>> &dp)
{
    if(curr==n)
    {
        return 0;
    }
    if(dp[curr][prev+1]!=-1)
    {
        return dp[curr][prev+1];
    }
    int skip=0+solve(words,n,curr+1,prev,dp);
    int take=0;
    if(prev==-1 || ispredecessor(words[prev],words[curr]))
    {
        take=1+solve(words,n,curr+1,curr,dp);
    }
    return dp[curr][prev+1]=max(skip,take);
}
int LSC(vector<string> &words)
{
    int n=words.size();
    if(n==0)
    {
        return 0;
    }
    sort(words.begin(),words.end(),[&](string &a,string &b){
        return a.size()<b.size();
    });
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solve(words,n, 0, -1,dp);
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;


    vector<string> v;
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        v.push_back(str);
    }

    cout<<LSC(v);




}