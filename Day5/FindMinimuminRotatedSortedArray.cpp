#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

// O(N) time complexity
int findMin(vector<int> &v)
{
    int s=0;
    int e=v.size()-1;
   
    while(s<e)
    {
        int mid=s+(e-s)/2;
        if(v[mid]>v[e])
        {
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return v[e];


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
    
    cout<<findMin(v);
    
    return 0;
}