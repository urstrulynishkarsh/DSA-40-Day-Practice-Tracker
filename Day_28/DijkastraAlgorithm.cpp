#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
using namespace std;
typedef pair<int,int> pii;


vector<int> DijkastraAlgorithm(int &V,vector<vector<int>>& edges, int &src)
{
    vector<vector<pii>> adj(V);
    for(auto edge:edges)
    {
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    vector<int> result(V,INT_MAX);
    result[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        // remember this case
        if(d>result[node])
        {
            continue;
        }
        for(auto nbr:adj[node])
        {
            int adjNode=nbr.first;
            int wt=nbr.second;
            if(wt+d<result[adjNode])
            {
                result[adjNode]=d+wt;
                pq.push({d+wt,adjNode});
            }
        }
    }
    return result;

}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i][0]
            >> edges[i][1]
            >> edges[i][2];
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> ans = DijkastraAlgorithm(V, edges, src);

    for(int i = 0; i < V; i++)
    {
        cout << i << " -> " << ans[i] << endl;
    }

    return 0;
}