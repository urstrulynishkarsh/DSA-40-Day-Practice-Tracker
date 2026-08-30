#include<iostream>
#include<vector>
#include<set>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void dfs(vector<vector<char>>& grid, int i, int j, int startI, int startJ,vector<pair<int,int> > &shape)
{
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='L')
    {
        return;
    }
    grid[i][j]='0';
    shape.push_back({i-startI,j-startJ});
    for(int k=0;k<4;k++)
    {
        int ii=i+dx[k];
        int jj=j+dy[k];
        dfs(grid,ii,jj,startI,startJ,shape);
    }
}
int numIslands(vector<vector<char>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    set<vector<pair<int,int> >> shapes;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='L')
            {
                vector<pair<int,int> > shape;
                dfs(grid,i,j,i,j,shape);
                shapes.insert(shape);
            }
        }
    }
    return shapes.size();
}
int main()
{
    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    cout << "Enter the grid (0 for water, 1 for land):" << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << "Number of Islands: " << numIslands(grid) << endl;

    return 0;
}