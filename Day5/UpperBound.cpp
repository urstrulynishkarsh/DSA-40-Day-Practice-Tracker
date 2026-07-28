#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

// O(N) time complexity
int upperbound(vector<int> &v, int target)
{
    int s=0;
    int e=v.size()-1;
    int res=v.size();
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(v[mid]>target)
        {
            res=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return res;


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
    cout<<upperbound(v,target);
    
    return 0;
}