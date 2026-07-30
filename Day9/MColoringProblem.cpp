#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int node, int color,vector<int> &colors,vector<vector<int> >adj)
{
    for(auto neighbor:adj[node])
    {
        if(colors[neighbor]==color)
        {
            return false;
        }
    }
    return true;
}
bool solve(int node, int V, int m,vector<int> &colors,vector<vector<int> >adj)
{
    if(node==V)
    {
        return true;
    }
    for(int color=1;color<=m;color++)
    {
        if(isSafe(node,color,colors,adj))
        {
            colors[node]=color;
            if(solve(node+1,V,m,colors,adj))
            {
                return true;
            }
            colors[node]=0;
        }
    }
    return false;
}
int main()
{
    int V, E, m;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int> >adj(V);
    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Enter number of colors: ";
    cin >> m;

    vector<int> colors(V,0);
    int node =0;
    cout<<solve(node,V,m,colors,adj);
}