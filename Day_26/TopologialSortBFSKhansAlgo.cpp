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

    void TopologicalSort(vector<int> &ans)
    {
        int n=nodes.size();
        vector<int> indegree(n,0);
        for(auto node:adjacencyList)
        {
            for(auto nbr:node.second)
            {
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for(auto node:nodes)
        {
            if(indegree[node]==0)
            {
                q.push(node);
            }
        }
        while(!q.empty())
        {
            int element=q.front();
            q.pop();
            ans.push_back(element);
            for(auto nbr:adjacencyList[element])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
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