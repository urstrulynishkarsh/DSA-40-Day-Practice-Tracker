#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

// O(N) time complexity
int maximumProductSubarray(vector<int> &v)
{
    int prefix=1;
    int suffix=1;
    int maxi=INT_MIN;
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        if(suffix==0)
        {
            suffix=1;
        }
        if(prefix==0)
        {
            prefix=1;
        }
        prefix*=v[i];
        suffix*=v[n-i-1];
        maxi=max(maxi,max(prefix,suffix));
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
    cout<<maximumProductSubarray(v);
    
    return 0;
}