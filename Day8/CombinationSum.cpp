#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;



void combinationSum(vector<int> &v, int target,vector<vector<int> > &result,vector<int> &ans , int index)
{
    if(target==0)
    {
        result.push_back(ans);
        return;
    }
    if(target<0)
    {
        return;
    }
    for(int i=index;i<v.size();i++)
    {
        ans.push_back(v[i]);
        combinationSum(v,target-v[i],result,ans,i);
        ans.pop_back();
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> v(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int target;
    cout<<"Enter the target value: ";
    cin>>target;
    vector<vector<int> > result;
    vector<int> ans;
    combinationSum(v,target,result,ans,0);
    for(auto V:result)
    {
        for(auto val:V)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}