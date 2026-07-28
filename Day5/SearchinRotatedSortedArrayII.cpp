#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

// O(N) time complexity
bool search(vector<int> &v, int target)
{
    int s=0;
    int e=v.size()-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(v[mid]==target)
        {
            return true;
        }
        if(v[s]==v[mid] && v[mid]==v[e])
        {
            s++;
            e--;
            continue;
        }
        if(v[s]<=v[mid])
        {
            if(v[s]<=target && target<v[mid])
            {
                
                e=mid-1;
            }
            else{
                
                s=mid+1;
            }
        }
        else if(v[mid]<=v[e])
        {
            if(v[mid]<target && target<=v[e])
            {
                 s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
    }
    return false;
    


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
    cout<<search(v,target);
    
    return 0;
}