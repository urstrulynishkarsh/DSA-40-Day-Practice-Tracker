#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
using namespace std;
typedef pair<int,int> pii;

vector<int> bellmanfordAlgo(int &V, vector<vector<int>>& edges, int &src)
{
    vector<int> result(V, INT_MAX);

    // Distance of source from itself
    result[src] = 0;

    // Relax all edges V-1 times
    for(int i = 1; i <= V - 1; i++)
    {
        bool updated = false;

        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // Relaxation
            if(result[u] != INT_MAX &&
               result[u] + w < result[v])
            {
                result[v] = result[u] + w;
                updated = true;
            }
        }

        // Optimization: if no distance changed, stop early
        if(!updated)
            break;
    }

    // Check for negative weight cycle
    for(auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(result[u] != INT_MAX &&
           result[u] + w < result[v])
        {
            // Negative weight cycle exists
            return {-1};
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

    vector<int> ans = bellmanfordAlgo(V, edges, src);

    // Negative cycle detected
    if(ans.size() == 1 && ans[0] == -1)
    {
        cout << "Negative weight cycle detected!" << endl;
        return 0;
    }

    cout << "\nShortest distances from source " << src << ":\n";

    for(int i = 0; i < V; i++)
    {
        if(ans[i] == INT_MAX)
            cout << i << " -> INF" << endl;
        else
            cout << i << " -> " << ans[i] << endl;
    }

    return 0;
}