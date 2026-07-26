#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

// O(N) time complexity
int majorityElementI(vector<int> &v)
{
    int freq=0;
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        if(freq==0)
        {
            ans=v[i];
        }
        if(ans==v[i])
        {
            freq++;
        }
        else{
            freq--;
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
    cout<<majorityElementI(v);
    
    return 0;
}