#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

// O(N) time complexity
int KadaneAlgorithm(vector<int> &v)
{
    int maxi=INT_MIN;
    int curr=0;
    for(int i=0;i<v.size();i++)
    {
        curr=max(v[i],curr+v[i]);
        maxi=max(maxi,curr);
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
    cout<<KadaneAlgorithm(v);
    
    return 0;
}