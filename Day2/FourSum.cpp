#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
using namespace std;


vector<vector<int>> FourSum(vector<int> &v, int target)
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
        for(int j=i+1;j<n;j++)
        {
            if(j>i+1 && v[j]==v[j-1])
            {
                continue;
            }
            int k=j+1;
            int l=n-1;
            while(k<l)
            {
                int sum=v[i]+v[j]+v[k]+v[l];
                if(sum<target)
                {
                    k++;
                }
                else if(sum>target)
                {
                    l--;
                }
                else{
                    result.push_back({v[i],v[j],v[k],v[l]});
                    k++;
                    l--;
                    while(k<l && v[k]==v[k-1])
                    {
                        k++;
                    }
                    while(k<l && v[l]==v[l+1])
                    {
                        l--;
                    }
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
    int target;
    cout<<"Enter the target value: ";
    cin>>target;
    vector<vector<int>>result=FourSum(v,target);
    for(auto V:result){
        for(int val:V)
            {
                cout<<val<<" ";
            }
            cout<<endl;
    }
    return 0;
}