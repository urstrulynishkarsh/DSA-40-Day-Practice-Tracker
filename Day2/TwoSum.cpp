#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
using namespace std;


vector<int> TwoSum(vector<int> &v, int target)
{
       
    unordered_map<int,int> mp;
    for(int i=0;i<v.size();i++)
    {
        int complement=target-v[i];
        if(mp.count(complement))
        {
            return {mp[complement],i};
        }
        mp[v[i]]=i;
    }
    return {-1,-1};


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
    vector<int> result=TwoSum(v,target);
    for(int val:result)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    return 0;
    
    return 0;
}