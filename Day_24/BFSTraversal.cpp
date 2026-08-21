#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>
#include<queue>
using namespace std;


class Graph{
    public:
        unordered_map<int, list<int>> adjacencyList;
        set<int> nodes;
        // addedge in list 
        void addEdge(int u, int v, bool direction)
        {
            nodes.insert(u);
            nodes.insert(v);
            if(direction==0)
            {
                adjacencyList[u].push_back(v);
                adjacencyList[v].push_back(u);
            }
            else{
                adjacencyList[u].push_back(v);
            }
        }
        void printGraph() {

        for(auto node : adjacencyList) {

            cout << node.first << " -> ";

            for(auto neighbor : node.second) {
                cout << neighbor << " ";
            }

            cout << endl;
        }
    }


    void BFS(int src)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            int frontnode=q.front();
            cout<<frontnode<<" ";
            q.pop();
            for(auto nbr:adjacencyList[frontnode])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }
};


int main()
{
    int n,e;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>e;
    Graph g;
    for(int i = 0; i < e; i++) {

        int u, v;
        cin >> u >> v;
        // 1 -> Directed
        // 0 -> Undirected
        g.addEdge(u, v, 1);
    }
    cout << "\nAdjacency List:\n";
    g.printGraph();

    int src;
    cout << "\nEnter the starting node for BFS: ";
    cin >> src;

    cout << "\nBFS Traversal:\n";
    g.BFS(src);
}