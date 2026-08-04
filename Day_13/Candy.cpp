#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> l2r(n,1);
        vector<int> r2l(n,1);

        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                l2r[i]=max(l2r[i],l2r[i-1]+1);
            }
        }

        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                r2l[i]=max(r2l[i],r2l[i+1]+1);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=max(l2r[i],r2l[i]);
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
    cout<<candy(v);
    
    return 0;
}