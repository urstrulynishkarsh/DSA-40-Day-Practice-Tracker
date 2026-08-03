#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
using namespace std;


int singleNumberII(vector<int> &v)
{
    int one=0;
    int two=0;
    for(int val:v)
    {
        one=one^val & ~two;
        two=two^val & ~one;
    }
    return one;

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
   
    cout<<singleNumberII(v);
    
    return 0;
}