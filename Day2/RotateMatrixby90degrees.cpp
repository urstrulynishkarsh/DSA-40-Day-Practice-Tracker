#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

void transpose(vector<vector<int> > &matrix, int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<m;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}
void Rotate(vector<vector<int> > &matrix, int n, int m)
{
    transpose(matrix,n,m);
    for(int i=0;i<n;i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
    
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
    Rotate(matrix,n,m);
    for(auto V:matrix){
        for(int val:V)
            {
                cout<<val<<" ";
            }
            cout<<endl;
    }
    return 0;
}