#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
using namespace std;


void floydWarshall(vector<vector<int>>& dist)
{
    int V = dist.size();

    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                // If both paths exist
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}


int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    // Initialize distance matrix
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    // Distance from vertex to itself = 0
    for(int i = 0; i < V; i++)
    {
        dist[i][i] = 0;
    }

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = w;
    }

    // Apply Floyd-Warshall
    floydWarshall(dist);

    cout << "\nShortest Distance Matrix:\n";

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}