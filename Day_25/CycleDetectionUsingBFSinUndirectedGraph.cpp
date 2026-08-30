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

    bool checkcycle(int src,unordered_map<int,bool> &visited)
    {
        queue<pair<int,int> > q;
        q.push({src,-1});

        visited[src]=true;
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();

            for(auto nbr:adjacencyList[node])
            {
                if(!visited[nbr])
                {
                    visited[nbr]=true;
                    q.push({nbr,node});
                }
                else if(nbr!=parent)
                {
                    return true;
                }

            }
        }
        return false;

    }
    
    void cycleDetectionBFS()
    {
        unordered_map<int,bool>visited;

        for(auto node:nodes)
        {
            if(!visited[node])
            {
                
                bool cycle=checkcycle(node,visited);
                if(cycle)
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
        // 1 -> Directed
        // 0 -> Undirected
        g.addEdge(u, v, 0);
    }
    cout << "\nAdjacency List:\n";
    g.printGraph();

    cout << "\nChecking cycle using DFS:\n"; 
    g.cycleDetectionBFS();
}