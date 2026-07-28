#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

long long calculateSum(vector<int> &v, int mid)
{
    long long sum=0;
    for(int i=0;i<v.size();i++)
    {
        sum+=ceil((double)v[i]/(double)mid);
    }
    return sum;
}

// O(N) time complexity
int smallestDivisor(vector<int> &v, int target)
{
    int maxi=*max_element(v.begin(),v.end());
    int s=1;
    int e=maxi;
    int ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        long long sum=calculateSum(v,mid);
        if(sum<=target)
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
    int target;
    cout<<"Enter the target value: ";
    cin>>target;
    cout<<smallestDivisor(v,target);
    
    return 0;
}