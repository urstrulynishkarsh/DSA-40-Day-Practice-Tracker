#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

// O(N) time complexity
int fruitintobasket(vector<int> &v)
{
    int n=v.size();
    int i=0;
    int j=0;
    int k=2;
    int maxi=1;
    unordered_map<int,int> mp;
    while(j<n)
    {
        mp[v[j]]++;
        while(mp.size()>k)
        {
            mp[v[i]]--;
            if(mp[v[i]]==0)
            {
                mp.erase(v[i]);
            }
            i++;
        }
        if(mp.size()<=k)
        {
            maxi=max(maxi,j-i+1);
        }
        j++;
    }
    return maxi;


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
    cout<<fruitintobasket(v);
    
    return 0;
}