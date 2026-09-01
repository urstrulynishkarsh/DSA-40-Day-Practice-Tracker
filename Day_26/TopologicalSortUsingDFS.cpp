#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>
#include<queue>
#include<deque>
using namespace std;

deque<int> dq;
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
    void dfs(int src, unordered_map<int,bool> &visited)
    {
        visited[src]=true;
        for(auto nbr:adjacencyList[src])
        {
            if(!visited[nbr])
            {
                dfs(nbr,visited);
            }
        }
        dq.push_back(src);
    }
    void TopologicalSort(vector<int> &ans)
    {
        int n=nodes.size();
        unordered_map<int,bool> visited;
        for(int node :nodes)
        {
            if(!visited[node])
            {
                dfs(node,visited);
            }
        }
       for(auto it=dq.rbegin(); it!=dq.rend(); it++)
    {
        ans.push_back(*it);
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
        g.addEdge(u, v, 1);
    }
    cout << "\nAdjacency List:\n";
    g.printGraph();
    vector<int> ans;
    g.TopologicalSort(ans);
    for(int val:ans)
    {
        cout<<val<<" ";
    }
    return 0;
}