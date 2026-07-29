#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;


bool searchin2DMatrixII(vector<vector<int> > &matrix, int n, int m, int target)
{
    int row=0;
    int col=m-1;
    while(row<n && col>=0)
    {
        if(matrix[row][col]==target)
        {
            return true;
        }
        else if(matrix[row][col]>target)
        {
            col--;
        }
        else{
            row++;
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
    cout<<searchin2DMatrixII(matrix,n,m,target);
    return 0;
}