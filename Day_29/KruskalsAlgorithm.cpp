#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> P;
vector<int> Rank;
vector<int> parent;

int find(int x)
{
    if(x==parent[x])
    {
        return x;
    }
    return parent[x]=find(parent[x]);
}

void unionset(int x, int y)
{
    int parent_x=find(x);
    int parent_y=find(y);
    if(parent_x==parent_y)
    {
        return;
    }
    if(Rank[parent_x]>Rank[parent_y])
    {
        parent[parent_y]=parent_x;
    }
    else if(Rank[parent_x]<Rank[parent_y])
    {
        parent[parent_x]=parent_y;
    }
    else{
        parent[parent_x]=parent_y;
        Rank[parent_y]++;
    }
}

int KruskalsAlgoithm(int n, vector<vector<int>> &vec)
{
    int sum=0;
    for(auto &temp:vec)
    {
        int u=temp[0];
        int v=temp[1];
        int wt=temp[2];
        int parent_u=find(u);
        int parent_v=find(v);
        if(parent_u!=parent_v)
        {
            unionset(u,v);
            sum+=wt;
        }
    }
    return sum;
}

int spanningTree(int V, vector<vector<P>>& edges) {
    parent.resize(V);
    Rank.resize(V,0);
    for(int i=0;i<V;i++)
    {
        parent[i]=i;
    }
    vector<vector<int> >vec;
    for(int u=0;u<V;u++)
    {
        for(auto &temp:edges[u])
        {
            int v=temp.first;
            int wt=temp.second;
            vec.push_back({u,v,wt});
        }
    }

    auto compar=[&](vector<int> &v1,vector<int> &v2)
    {
        return v1[2]<v2[2];
    };

    sort(begin(vec),end(vec),compar);

    return KruskalsAlgoithm(V,vec);
        
}


int main()
{
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    int E;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<P>> edges(V);

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++)
    {
        int u, v, wt;

        cin >> u >> v >> wt;

        edges[u].push_back({v, wt});
        edges[v].push_back({u, wt});
    }

    int ans = spanningTree(V, edges);

    cout << "Weight of MST: " << ans << endl;

    return 0;
}
