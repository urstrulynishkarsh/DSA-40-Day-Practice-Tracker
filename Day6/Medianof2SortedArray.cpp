#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;


double medianofSortedArray(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size();
        int m=b.size();
        if(n>m)
        {
            return medianofSortedArray(b,a);
        }
        int s=0;
        int e=n;
        int left=(n+m+1)/2;
        int totalsize=n+m;
        while(s<=e)
        {
            int mid1=s+(e-s)/2;
            int mid2=left-mid1;
            
            int x1=mid1==0?INT_MIN:a[mid1-1];
            int x2=mid2==0?INT_MIN:b[mid2-1];
            int x3=mid1==n?INT_MAX:a[mid1];
            int x4=mid2==m?INT_MAX:b[mid2];
            
            
            if(x1<=x4 && x2<=x3)
            {
                if(totalsize&1)
                {
                    return max(x1,x2);
                }
                return (max(x1,x2)+min(x3,x4))/2.0;
            }
            if(x1>x4)
            {
                e=mid1-1;
            }
            else{
                s=mid1+1;
            }
        }
        return -1;
    }

int main()
{
    int n;
    cout<<"Enter the first size of array: ";
    cin>>n;

    vector<int> a(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int m;
    cout<<"Enter the second size of array: ";
    cin>>m;

    vector<int> b(m);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    cout<<medianofSortedArray(a,b);

    
    return 0;
}