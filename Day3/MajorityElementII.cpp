#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
using namespace std;


vector<int> MajorityElementII(vector<int> &v)
{
    int n=v.size();
    int count1 = 0, count2 = 0;
    int candidate1 = 0, candidate2 = 0;
    for(int val:v)
    {
        if(val==candidate1)
        {
            count1++;
        }
        else if(val==candidate2)
        {
            count2++;
        }
        else if(count1==0)
        {
            candidate1=val;
            count1++;
        }
        else if(count2==0)
        {
            candidate2=val;
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1=0;
    count2=0;
    for(int val:v)
    {
        if(val==candidate1)
        {
            count1++;
        }
        else if(val==candidate2)
        {
            count2++;
        }
    }
    vector<int> ans;
    if(count1>n/3)
    {
        ans.push_back(candidate1);
    }
    if(count2>n/3)
    {
        ans.push_back(candidate2);
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
    vector<int> result=MajorityElementII(v);
    for(int val:result)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    return 0;
    
    return 0;
}