#include<iostream>
#include<vector>
using namespace std;

int findCheapestPrice(int &V,vector<vector<int>> &edges,int &src, int &dest,int &k)
{
    vector<vector<pair<int,int>>>adj(V);
    for(auto edge:edges)
    {
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        adj[u].push_back({v,w});
    }

    queue<pair<int,int>>q;
    q.push({0,src});
    vector<int> result(V,INT_MAX);
    result[src]=0;
    int steps=0;
    while(!q.empty() && steps<=k)
    {
        int N=q.size();
        while(N--)
        {
            int d=q.front().first;
            int node=q.front().second;
            q.pop();
            for(auto &nbr:adj[node])
            {
                int cost=nbr.second;
                int adjNode=nbr.first;
                if(d+cost<result[adjNode])
                {
                    result[adjNode]=d+cost;
                    q.push({d+cost,adjNode});
                }

            }
        }
        steps++;
    }
    if(result[dest]==INT_MAX)
    {
        return -1;
    }
    return result[dest];

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

    int src,dest;
    cout<<"Enter the src and dest: ";
    cin>>src>>dest;


    int k;
    cout<<"Enter the k value: ";
    cin>>k;

    cout<<findCheapestPrice(V,edges,src,dest,k);

    

    return 0;
}