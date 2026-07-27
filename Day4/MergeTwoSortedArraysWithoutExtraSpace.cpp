#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;


void mergeArray(vector<int> &a , vector<int> &b, int n, int m)
{
    int s=0;
    int e=n+m-1;
    int totalsize=e-s+1;
    int gap=(totalsize/2)+(totalsize%2);
    while(gap>0)
    {
        int i=s;
        int j=s+gap;
        while(j<=e)
        {
            if(i<n && j<n)
            {
                if(a[i]>a[j])          // <-- corrected
                {
                    swap(a[i],a[j]);   // <-- corrected
                }
            }
            else if(i<n && j>=n)
            {
                if(a[i]>b[j-n])
                {
                    swap(a[i],b[j-n]);
                }
            }
            else{
                if(b[i-n]>b[j-n])
                {
                    swap(b[i-n],b[j-n]);
                }
            }
            i++;
            j++;
        }
        gap=gap<=1?0:(gap/2+gap%2);

    }
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
    mergeArray(a,b,n,m);

        for(int val:a)
        {
            cout<<val<<" ";
        }
        cout<<endl;

         for(int val:b)
        {
            cout<<val<<" ";
        }
        cout<<endl;

    
    return 0;
}