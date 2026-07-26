#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
using namespace std;


vector<int> repeatingandmissing(vector<int> &v)
{
    // swap sort
    for(int i=0;i<v.size();i++)
    {
        int correct_position=v[i]-1;
        while(v[correct_position]!=v[i])
        {
            swap(v[correct_position],v[i]);
            correct_position=v[i]-1;
        }
    }


    for(int i=0;i<v.size();i++)
    {
        if(v[i]!=i+1)
        {
            return {v[i],i+1};
        }
    }
    return {-1,-1};

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
    vector<int> result=repeatingandmissing(v);
    for(int val:result)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    return 0;
    
    return 0;
}