#include<iostream>
#include<vector>
#include<queue>
using namespace std;




   typedef pair<int,int> P;
    int PrimsAlgoithm(int n, vector<vector<P>> &adj)
{
    priority_queue<P,vector<P>,greater<P> >pq;
    pq.push({0,0});
    int sum=0;
    vector<bool> inMST(n,false);
    while(!pq.empty())
    {
        int wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(inMST[node]==true)
        {
            continue;
        }
        inMST[node]=true;
        sum+=wt;
        for(auto &nbr:adj[node])
        {
            int neigbor=nbr.first;
            int neigbor_cost=nbr.second;
            if(inMST[neigbor]==false)
            {
                pq.push({neigbor_cost,neigbor});
            }
        }
    }
    return sum;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<P>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int dist=abs(x2-x1)+abs(y2-y1);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        return PrimsAlgoithm(n,adj);
        
    }


int main()
{
    int n;

    cout << "Enter number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    cout << "Enter x and y coordinates:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    int ans = minCostConnectPoints(points);

    cout << "Minimum Cost to Connect All Points: " << ans << endl;

    return 0;
}