#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> P;

int PrimsAlgoithm(int n, vector<vector<P>> &adj)
{
    priority_queue<P,vector<P>,greater<P> >pq;
    pq.push({0,0});
    int sum=0;
    vector<bool> inMST(n,false);
    while(!pq.empty())
    {
        int wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(inMST[node]==true)
        {
            continue;
        }
        inMST[node]=true;
        sum+=wt;
        for(auto &nbr:adj[node])
        {
            int neigbor=nbr.first;
            int neigbor_cost=nbr.second;
            if(inMST[neigbor]==false)
            {
                pq.push({neigbor_cost,neigbor});
            }
        }
    }
    return sum;
}


int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<P>> adj(n);

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int ans = PrimsAlgoithm(n, adj);

    cout << "Weight of MST: " << ans << endl;

    return 0;
}
