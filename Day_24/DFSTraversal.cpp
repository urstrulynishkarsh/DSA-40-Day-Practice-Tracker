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

    void dfshelper(int src, unordered_map<int,bool> &visited)
    {
        visited[src]=true;
        cout<<src<<" ";
        for(auto nbr: adjacencyList[src])
        {
            if(!visited[nbr])
            {
                dfshelper(nbr,visited);
            }
        }
    }
    void DFS()
    {
        unordered_map<int,bool> visited;
        for(auto node:nodes)
        {
            if(!visited[node])
            {
                dfshelper(node,visited);
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
        g.addEdge(u, v, 0);
    }
    cout << "\nAdjacency List:\n";
    g.printGraph();


    cout << "\nDFS Traversal:\n";
    g.DFS();
}