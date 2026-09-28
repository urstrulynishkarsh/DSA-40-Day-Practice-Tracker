#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
using namespace std;


int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
    vector<vector<int>> adj(V);
    for(auto edge:edges)
    {
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<pair<int,int> >q;
    unordered_map<int,bool> visited;
    q.push({src,0});
    visited[src]=true;
    while(!q.empty())
    {
        int node=q.front().first;
        int distance=q.front().second;
        q.pop();
        if(node==dest)
        {
            return distance;
        }
        for(auto nbr:adj[node])
        {
            if(!visited[nbr])
            {
                visited[nbr]=true;
                q.push({nbr,distance+1});
            }
        }
    }
    return -1;

}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    cout << "Enter edges (u v):\n";

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    int src, dest;

    cout << "Enter source: ";
    cin >> src;

    cout << "Enter destination: ";
    cin >> dest;

    int ans = shortestPath(V, edges, src, dest);

    cout << "Shortest path distance: " << ans << endl;

    return 0;
}