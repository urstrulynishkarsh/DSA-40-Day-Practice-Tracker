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


    bool checkcycle(int src,unordered_map<int, bool> &visited,unordered_map<int, bool> &dfschecker)
    {
        visited[src]=true;
        dfschecker[src]=true;
        for(auto nbr:adjacencyList[src])
        {
            if(!visited[nbr])
            {
                if(checkcycle(nbr,visited,dfschecker))
                {
                    return true;
                }
                else if(dfschecker[nbr])
                {
                    return true;
                }
            }
        }
        // DFS of this node is completed
        dfschecker[src] = false;
        return false;

    }
   
    void cycleDetectionDFS()
    {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfschecker;

        for(auto node:nodes)
        {
            if(!visited[node])
            {
                if(checkcycle(node,visited,dfschecker))
                {
                    cout << "Cycle is present" << endl;
                    return;
                }
            }
        }
        cout << "Cycle is not present" << endl;

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
        g.addEdge(u, v, 1);
    }
    cout << "\nAdjacency List:\n";
    g.printGraph();

    cout << "\nChecking cycle using DFS:\n"; 
    g.cycleDetectionDFS();
}