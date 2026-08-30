#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void dfs(vector<vector<int> > &matrix,int i, int j,int time)
{
    if(i<0 or j<0 or i>=matrix.size() or j>=matrix[0].size() || matrix[i][j]!=1 && matrix[i][j]<time)
    {
        return;
    }
    matrix[i][j] = time;
    for(int k=0;k<4;k++)
    {
        int ii=i+dx[k];
        int jj=j+dy[k];
        dfs(matrix,ii,jj,time+1);
    }
}


int rottenOrange(vector<vector<int> >matrix)
{
    int row=matrix.size();
    int col=matrix[0].size();
    int ellapsedtime=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]==2)
            {
                dfs(matrix,i,j,2);
            }
        }
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]==1)
            {
                return -1;
            }
            ellapsedtime=max(ellapsedtime,matrix[i][j]-2);
        }
    }
    return ellapsedtime;

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
   

cout<<rottenOrange(matrix);



    return 0;
}