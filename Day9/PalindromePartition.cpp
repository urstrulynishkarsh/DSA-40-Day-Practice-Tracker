#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;

bool checkplaindrome(string &s, int i, int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void palindromicPartition(string &str,vector<vector<string>> &result,vector<string> &ans,int index)
{
    if(index==str.length())
    {
        result.push_back(ans);
        return;
    }
    for(int i=index;i<str.length();i++)
    {
        if(checkplaindrome(str,index,i))
        {
            ans.push_back(str.substr(index,i-index+1));
            palindromicPartition(str,result,ans,i+1);
            ans.pop_back();
        }
    }
}
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    vector<vector<string>> result;
    vector<string> ans;
    palindromicPartition(str,result,ans,0);
    for(auto strs:result)
    {
        for(auto str:strs)
        {
            cout<<str<<" ";
        }
        cout<<endl;
    }
    return 0;

}