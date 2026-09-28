#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
using namespace std;


    
void dfs(int src,unordered_map<int,bool> &visited,stack<int> &st,vector<vector<pair<int,int>>> &adj)
{
    visited[src]=true;
    for(auto &it:adj[src])
    {
        if(!visited[it.first])
        {
            dfs(it.first,visited,st,adj);
        }
    }
    st.push(src);
}
vector<int> shortestPath(int V, int E,vector<vector<int>>& edges)
{
    // Adjacency list: {node -> {adjacent_node, weight}}
    vector<vector<pair<int,int>>>adj(V);
    for(auto edge:edges)
    {
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        adj[u].push_back({v,w});
    }
    unordered_map<int,bool> visited;
    stack<int> st;

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,st,adj);
        }
    }

    const int INF=1e9;
    vector<int> dist(V,INF);
    dist[0]=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(dist[node]!=INF)
        {
            for(auto &it:adj[node])
            {
                int v=it.first;
                int w=it.second;
                if(dist[node]+w<dist[v])
                {
                    dist[v]=dist[node]+w;
                }
            }
        }
    }
    for(int i=0;i<V;i++)
    {
        if(dist[i]==INF)
        {
            dist[i]=-1;
        }
    }
    return dist;

}

int main()
{
    int V,E;

    cout<<"Enter number of vertices: ";
    cin>>V;

    cout<<"Enter number of edges: ";
    cin>>E;

    vector<vector<int>> edges(E,vector<int>(3));

    cout<<"Enter edges (u v weight):\n";

    for(int i=0;i<E;i++)
    {
        cin>>edges[i][0]
           >>edges[i][1]
           >>edges[i][2];
    }

    vector<int> ans=shortestPath(V,E,edges);

    cout<<"Shortest distances from node 0:\n";

    for(int i=0;i<V;i++)
    {
        cout<<i<<" -> "<<ans[i]<<endl;
    }

    return 0;
}