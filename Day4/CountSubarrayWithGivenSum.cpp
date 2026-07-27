

#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;


int longestArrayWithSumK(vector<int> &v, int k)
{
    unordered_map<int,int> mp;
    mp[0]=1;
    int count=0;
    int prefix=0;
    for(int i=0;i<v.size();i++)
    {
        prefix+=v[i];
        if(mp.find(prefix-k)!=mp.end())
        {
            count+=mp[prefix-k];
        }
        mp[prefix]++;
    }
    return count;

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