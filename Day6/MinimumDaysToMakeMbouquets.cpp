#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

bool canPossible(vector<int> &v, int m, int k, int day)
{
    int flowers=0;
    int bouquets=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<=day)
        {
            flowers++;
        }
        else{
            flowers=0;
        }
        if(flowers==k)
        {
            bouquets++;
            flowers=0;
        }
    }
    return bouquets>=m;
}

int minDays(vector<int> &v, int m, int k)
{
    int s=*min_element(v.begin(),v.end());
    int e=*max_element(v.begin(),v.end());
    int ans=-1;
    if((long long)m*k>v.size())
    {
        return ans;
    }
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(canPossible(v,m,k,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
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
    int m;
    cout<<"Enter the m value: ";
    cin>>m;
    int k;
    cout<<"Enter the k value: ";
    cin>>k;
    cout<<minDays(v,m,k);
    
    return 0;
}