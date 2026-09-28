#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> Rank;
vector<int> parent;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

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

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    parent.resize(n*m);
    Rank.resize(n*m,0);
    for(int i=0;i<n*m;i++)
    {
        parent[i]=i;
    }
    vector<vector<int>> grid(n,vector<int> (m,0));

    vector<int> ans;

    int islands=0;

    for(auto &op:operators)
    {
        int i=op[0];
        int j=op[1];

        if(grid[i][j]==1)
        {
            ans.push_back(islands);
            continue;
        }

        grid[i][j]=1;
        islands++;
        // which node 
        int node=i*m+j;

        for(int k=0;k<4;k++)
        {
            int ii=i+dx[k];
            int jj=j+dy[k];

            if(ii>=0 && ii<n && jj>=0 && jj<m  && grid[ii][jj]==1)
            {
                int neighbor=ii*m+jj;
                if(find(node)!=find(neighbor))
                {
                    unionset(node,neighbor);
                    islands--;
                }
            }
        }
        ans.push_back(islands);

    }
    return ans;      
}

int main()
{
    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    int k;

    cout << "Enter number of operations: ";
    cin >> k;

    vector<vector<int>> operators(k, vector<int>(2));

    cout << "Enter operations (row column):\n";

    for(int i = 0; i < k; i++)
    {
        cin >> operators[i][0] >> operators[i][1];
    }

    vector<int> ans = numOfIslands(n, m, operators);

    cout << "Number of islands after each operation:\n";

    for(int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}