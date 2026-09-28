#include<iostream>
#include<vector>
using namespace std;

typedef pair<int,pair<int,int>> P;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int pathwithMinimumEffort(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    priority_queue<P,vector<P>,greater<P>>pq;
    pq.push({0,{0,0}});
    vector<vector<int> >result(n,vector<int>(m,INT_MAX));
    result[0][0]=0;
    while(!pq.empty())
    {
        int d=pq.top().first;
        pair<int,int> node=pq.top().second;
        int x=node.first;
        int y=node.second;
        pq.pop();
        for(int k=0;k<4;k++)
        {
            int newx=x+dx[k];
            int newy=y+dy[k];
            if(newx<0 ||newy<0 ||newx>=n ||newy>=m)
            {
                continue;
            }
            int newd=max(d,abs(matrix[newx][newy]-matrix[x][y]));
            if(newd<result[newx][newy])
            {
                result[newx][newy]=newd;
                pq.push({newd,{newx,newy}});
            }
        }
    }
    return result[n-1][m-1];
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
    cout<<pathwithMinimumEffort(matrix);
}