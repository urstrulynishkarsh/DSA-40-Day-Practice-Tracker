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
    int sum=0;
    int c=1;
    for(int val:v)
    {
        sum+=val;
        if(sum>mid)
        {
            c++;
            sum=val;
        }
        if(c>k)
        {
            return false;
        }
    }
    return true;
}


int bookAllocationProblem(vector<int> &v, int k)
{
    int n=v.size();
    int ans=-1;
    if(n<k)
    {
        return ans;
    }
    int s=*max_element(v.begin(),v.end());
    int e=accumulate(v.begin(),v.end(),0);
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(isPossible(v,k,mid))
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
    int k;
    cout<<"Enter the k value: ";
    cin>>k;
    cout<<bookAllocationProblem(v,k);
    
    return 0;
}