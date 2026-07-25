#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

void merge(vector<int> &v, int s, int e, int mid)
{
    int len1=mid-s+1;
    int len2=e-mid;
    vector<int> v1(len1);
    vector<int> v2(len2);
    int k=s;
    for(int i=0;i<len1;i++)
    {
        v1[i]=v[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        v2[i]=v[k++];
    }

    int leftindex=0;
    int rightindex=0;
    int mainindex=s;
    while(leftindex<len1 && rightindex<len2)
    {
        if(v1[leftindex]<v2[rightindex])
        {
            v[mainindex++]=v1[leftindex++];
        }
        else{
            v[mainindex++]=v2[rightindex++];
        }
    }
    while(leftindex<len1)
    {
        v[mainindex++]=v1[leftindex++];
    }
    while(rightindex<len2)
    {
        v[mainindex++]=v2[rightindex++];
    }

}
void mergeSortAlgo(vector<int> &v, int s, int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=s+(e-s)/2;
    mergeSortAlgo(v,s,mid);
    mergeSortAlgo(v,mid+1,e);
    merge(v,s,e,mid);
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
    int s=0;
    int e=v.size()-1;
    mergeSortAlgo(v,s,e);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}