#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;
vector<int> Rank;

int find(int x)
{
    if(x==parent[x])
    {
        return x;
    }
    return parent[x]=find(parent[x]);
}

void unionset(int x , int y)
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
    else if(Rank[parent_x]>Rank[parent_y])
    {
        parent[parent_x]=parent_y;
    }
    else{
        parent[parent_x]=parent_y;
        Rank[parent_y]++;
    }
}

int numofoperation(int n, vector<vector<int>> &connections)
{
    int size=connections.size();
    if(size<n-1)
    {
        return -1;
    }
    parent.resize(n);
    Rank.resize(n,0);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int components=n;
    for(auto edge:connections)
    {
        int u=edge[0];
        int v=edge[1];
        if(find(u)!=find(v))
        {
            unionset(u,v);
            components--;
        }
    }
    return components-1;
}

int main()
{
    int n;
    cout << "Enter number of computers: ";
    cin >> n;

    int m;
    cout << "Enter number of connections: ";
    cin >> m;

    vector<vector<int>> connections(m, vector<int>(2));

    cout << "Enter connections:\n";

    for(int i = 0; i < m; i++)
    {
        cin >> connections[i][0] >> connections[i][1];
    }

    int ans = numofoperation(n, connections);

    cout << "Minimum number of operations: " << ans << endl;

    return 0;
}