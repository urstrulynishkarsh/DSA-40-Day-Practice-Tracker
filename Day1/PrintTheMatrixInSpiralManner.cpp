#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

vector<int > printSpiralMatrix(vector<vector<int> > &matrix, int n, int m)
{
    int top=0;
    int bottom=n-1;
    int left=0;
    int right=m-1;
    vector<int> ans;
    while(top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
        }
        bottom--;
        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
            }
        }
        left++;
    }
    return ans;
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
    vector<int> result=printSpiralMatrix(matrix,n,m);
    
        for(int val:result)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    return 0;
}