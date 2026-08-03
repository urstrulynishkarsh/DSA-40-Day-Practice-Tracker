#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
using namespace std;


vector<vector<int>> ThreeSum(vector<int> &v)
{
    int n=v.size();
    sort(v.begin(),v.end());
    vector<vector<int> >result;
    for(int i=0;i<n;i++)
    {
        if(i>0 && v[i]==v[i-1])
        {
            continue;
        }
        int j=i+1;
        int k=n-1;

        while(j<k)
        {
            int sum=v[i]+v[j]+v[k];
            if(sum<0)
            {
                j++;
            }
            else if (sum>0)
            {
                k--;
            }
            else{
                result.push_back({v[i],v[j],v[k]});
                j++;
                k--;
                while(j<k && v[j]==v[j-1])
                {
                    j++;
                }
            }
        }
    }
    return result;

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
    
    vector<vector<int>>result=ThreeSum(v);
    for(auto V:result){
        for(int val:V)
            {
                cout<<val<<" ";
            }
            cout<<endl;
    }
    return 0;
}