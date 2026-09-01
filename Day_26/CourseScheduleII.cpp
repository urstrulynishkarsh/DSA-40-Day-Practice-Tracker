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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int> >adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto nbr:prerequisites)
        {
            adj[nbr[1]].push_back(nbr[0]);
            indegree[nbr[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto nbr:adj[front])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
        if(ans.size()==numCourses)
        {
            return ans;
        }
        else{
            return {};
        }
    }
};


int main()
{
    int numCourses, p;

    cout << "Enter number of courses: ";
    cin >> numCourses;

    cout << "Enter number of prerequisites: ";
    cin >> p;

    vector<vector<int>> prerequisites(p, vector<int>(2));

    cout << "Enter prerequisites [course prerequisite]:\n";

    for(int i = 0; i < p; i++)
    {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    Graph g;

    vector<int> ans = g.findOrder(numCourses, prerequisites);

    if(ans.empty())
    {
        cout << "No valid ordering exists." << endl;
    }
    else
    {
        cout << "Course Order: ";

        for(int course : ans)
        {
            cout << course << " ";
        }

        cout << endl;
    }

    return 0;
}