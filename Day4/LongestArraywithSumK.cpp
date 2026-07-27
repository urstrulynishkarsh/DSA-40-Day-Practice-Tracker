

#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

// O(N) time complexity
int longestArrayWithSumK(vector<int> &v, int k)
{
    unordered_map<int,int> mp;
    int sum=0;
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        if(sum==k)
        {
            ans=i+1;
        }
        if(mp.find(sum-k)!=mp.end())
        {
            ans=max(ans,i-mp[sum-k]);
        }
        if(mp.find(sum)==mp.end())
        {
            mp[sum]=i;
        }
    }
    return ans;


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
    int k;
    cout<<"Enter the k value: ";
    cin>>k;
    cout<<longestArrayWithSumK(v,k);
    
    return 0;
}