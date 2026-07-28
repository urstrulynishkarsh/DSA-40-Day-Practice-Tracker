#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<algorithm>
#include<limits>
#include<numeric>
using namespace std;

bool isPossible(vector<int> &v, int k, int mid)
{
    int pos=v[0];
    int c=1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]-pos>=mid)
        {
            c++;
            pos=v[i];
        }
        if(c>=k)
        {
            return true;
        }
    }
    return false;
    
}


int AggresiveCow(vector<int> &v, int k)
{
    int n=v.size();
    sort(v.begin(),v.end());
    int s=1;
    int e=v[n-1]-v[0];
    int ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(isPossible(v,k,mid))
        {
            ans=mid;
            s=mid+1;
            
        }
        else{
            e=mid-1;
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
    cout<<AggresiveCow(v,k);
    
    return 0;
}