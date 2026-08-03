#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
using namespace std;


vector<int> singleNumberIII(vector<int> &v)
{
    int xor_r=0;
    for(int val:v)
    {
        xor_r^=val;
    }
    int mask=xor_r &(-xor_r);
    int groupa=0;
    int groupb=0;
    for(int val:v)
    {
        if(mask&val)
        {
            groupa^=val;
        }
        else{
            groupb^=val;
        }
    }
    return {groupa,groupb};

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
   
    vector<int> result=singleNumberIII(v);
     for(int val:result)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    return 0;
}