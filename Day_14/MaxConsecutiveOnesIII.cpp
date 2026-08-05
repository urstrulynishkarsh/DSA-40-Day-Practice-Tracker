#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

// O(N) time complexity
int maximumconsecutiveoneIII(vector<int> &v, int k)
{
    int n=v.size();
    int i=0;
    int j=0;
    int zero=0;
    int maxi=INT_MIN;
    while(j<n)
    {
        // calculation
        if(v[j]==0)
        {
            zero++;
        }
        // shrink
        while(zero>k)
        {
            if(v[i]==0)
            {
                zero--;
            }
            i++;
        }
        maxi=max(maxi,j-i+1);
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
    int k;
    cout<<"Enter the k  value: ";
    cin>>k;
    cout<<maximumconsecutiveoneIII(v,k);
    
    return 0;
}