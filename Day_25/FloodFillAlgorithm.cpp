#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void dfs(vector<vector<int> > &matrix,int i, int j,int oldcolor,int color)
{
    if(i<0 or j<0 or i>=matrix.size() or j>=matrix[0].size() || matrix[i][j]!=oldcolor)
    {
        return;
    }
    matrix[i][j] = color;
    for(int k=0;k<4;k++)
    {
        int ii=i+dx[k];
        int jj=j+dy[k];
        dfs(matrix,ii,jj,oldcolor,color);
    }
}


vector<vector<int>> floodFill(vector<vector<int> >matrix,int sr, int sc,int color)
{
    if(matrix[sr][sc]==color)
    {
        return matrix;
    }
    int oldcolor=matrix[sr][sc];
    dfs(matrix,sr,sc,oldcolor,color);
    return matrix;
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
    int sr,sc;
    cout<<"Enter the value of sr and sc: ";
    cin>>sr>>sc;

    int color;
    cout<<"Enter the color: ";
    cin>>color;

vector<vector<int>>result= floodFill(matrix,sr,sc,color);
for(auto val:result)
{
    for(auto v:val)
    {
        cout<<v<<" ";
    }
    cout<<endl;
}


    return 0;
}