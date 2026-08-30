#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

bool isBipartite(vector<vector<int> >matrix)
{
    int n=matrix.size();
    vector<int> color(n,-1);
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            color[i]=0;
        }
        else{
            continue;
        }
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int nbr:matrix[node])
            {
                if(color[nbr]==color[node])
                {
                    return false;
                }
                if(color[nbr]==-1)
                {   color[nbr]=1-color[node];
                    q.push(nbr);
                }
            }
        }
    }
    return true;

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
   

cout<<isBipartite(matrix);



    return 0;
}