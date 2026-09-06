#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
using namespace std;


 void floydWarshelAlgo(int n,vector<vector<int> > &shortestPathMatrix)
    {
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    shortestPathMatrix[i][j]=min(shortestPathMatrix[i][j],shortestPathMatrix[i][via]+shortestPathMatrix[via][j]);
                }
            }
        }
    }

    int result(int n,vector<vector<int> > &shortestPathMatrix,int & distanceThreshold)
    {
        int city=-1;
        int leastreachcount=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && shortestPathMatrix[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(count<=leastreachcount)
            {
                leastreachcount=count;
                city=i;
            }
        }
        return city;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int> >shortestPathMatrix(n,vector<int> (n,1e8));
        for(int i=0;i<n;i++)
        {
            shortestPathMatrix[i][i]=0;
        }
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            shortestPathMatrix[u][v]=w;
            shortestPathMatrix[v][u]=w;
        }
        
        floydWarshelAlgo(n,shortestPathMatrix);
        return result(n,shortestPathMatrix,distanceThreshold);

        
    }


int main()
{
    int n;

    cout << "Enter number of cities: ";
    cin >> n;

    int m;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int distanceThreshold;

    cout << "Enter distance threshold: ";
    cin >> distanceThreshold;

    int ans = findTheCity(n, edges, distanceThreshold);

    cout << "City with smallest number of reachable cities: "
         << ans << endl;

    return 0;
}