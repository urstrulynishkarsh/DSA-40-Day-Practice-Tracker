#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int Partition(vector<int> &v, int s, int e)
{
    // choose pivotelement and index
    int pivotindex=s;
    int pivotelement=v[s];

    // find how mnay number is smaller
    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(v[i]<=pivotelement)
        {
            count++;
        }
    }

    // swap it
    int rightindex=s+count;
    swap(v[pivotindex],v[rightindex]);
    pivotindex=rightindex;


    int i=s;
    int j=e;

    while(i<pivotindex && j>pivotindex)
    {
        while(v[i]<=pivotelement)
        {
            i++;
        }
        while(v[j]>pivotelement)
        {
            j--;
        }



        if(i<pivotindex && j>pivotindex)
        {
            swap(v[i],v[j]);
        }
    }
    return pivotindex;



}


void quickSortAlgo(vector<int> &v, int s, int e)
{
    if(s>=e)
    {
        return;
    }
    int p=Partition(v,s,e);

    quickSortAlgo(v,s,p-1);
    quickSortAlgo(v,p+1,e);


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
    quickSortAlgo(v,s,e);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}