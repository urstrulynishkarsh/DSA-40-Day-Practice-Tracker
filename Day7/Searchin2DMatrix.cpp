#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;


bool searchin2DMatrix(vector<vector<int> > &matrix, int n, int m, int target)
{
    int s=0;
    int total=n*m;
    int e=total-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int i=mid/m;
        int j=mid%m;
        if(matrix[i][j]==target)
        {
            return true;
        }
        else if(matrix[i][j]>target)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return false;

    
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
    int target;
    cout<<"Enter the target value: ";
    cin>>target;
    cout<<searchin2DMatrix(matrix,n,m,target);
    return 0;
}