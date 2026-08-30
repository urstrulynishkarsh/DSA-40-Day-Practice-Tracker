#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void dfs(vector<vector<char> > &matrix,int i, int j)
{
    if(i<0 or j<0 or i>=matrix.size() or j>=matrix[0].size() || matrix[i][j]!='O')
    {
        return;
    }
    matrix[i][j] ='#' ;
    for(int k=0;k<4;k++)
    {
        int ii=i+dx[k];
        int jj=j+dy[k];
        dfs(matrix,ii,jj);
    }
}


void surroundedRegion(vector<vector<char> >matrix)
{
        int row=matrix.size();
        int col=matrix[0].size();
        for(int j=0;j<col;j++)
        {
            if(matrix[0][j]=='O')
            {
                dfs(matrix,0,j);
            }
            if(matrix[row-1][j]=='O')
            {
                dfs(matrix,row-1,j);
            }
        }

         for(int j=0;j<row;j++)
        {
            if(matrix[j][0]=='O')
            {
                dfs(matrix,j,0);
            }
            if(matrix[j][col-1]=='O')
            {
                dfs(matrix,j,col-1);
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]=='O')
                {
                    matrix[i][j]='X';
                }
            }
        }

          // 4. Restore safe O's
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == '#')
                {
                    matrix[i][j] = 'O';
                }
            }
        }


}
int main()
{
    int n,m;
    cout<<"Enter the row and col: ";
    cin>>n>>m;
    vector<vector<char> >matrix(n,vector<char>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
   

    surroundedRegion(matrix);
    for(auto val:matrix)
{
    for(auto v:val)
    {
        cout<<v<<" ";
    }
    cout<<endl;
}


    return 0;
}