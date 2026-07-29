#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int binary(int i,vector<vector<int> > &matrix)
{
    int s=0;
    int e=matrix[0].size()-1;
    sort(matrix[i].begin(),matrix[i].end());
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(matrix[i][mid]==1)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return matrix[i].size()-s;
}
vector<int> rowAndMaximumOnes(vector<vector<int> > &matrix, int n, int m)
{
    int index=0;
    int maxones=0;
    for(int i=0;i<n;i++)
    {
        int temp=binary(i,matrix);
        if(temp>maxones)
        {
            index=i;
            maxones=temp;
        }
    }
    return {index,maxones};

    
}


int main()
{
    int n,m;
    cout<<"Enter the row and col: ";
    cin>>n>>m;
    vector<vector<int> >matrix(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    vector<int> result= rowAndMaximumOnes(matrix,n,m);
   
        for(int val:result)
            {
                cout<<val<<" ";
            }
            cout<<endl;

    return 0;
}