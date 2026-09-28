// 5. Bipartite Graph – Print One Color Set

// You're given an undirected graph with N nodes as an adjacency matrix. The graph may be disconnected.

// If the graph is bipartite, print all nodes in the same color group as node 0 (in increasing order). Otherwise, print -1.

// Example 1

// Input:
// 4
// 0 1 0 1
// 1 0 1 0
// 0 1 0 1
// 1 0 1 0
// Output: 0 2

// Explanation: It's a square 0–1–2–3–0. Nodes {0, 2} get one color, {1, 3} the other.

// Example 2

// Input:
// 3
// 0 1 1
// 1 0 1
// 1 1 0
// Output: -1

// Explanation: A triangle can't be 2-colored.
#include<bits/stdc++.h>
using namespace std;


int n;
int arr[100][100]={0};




int main()
{
    cin>>n;
    int color[n];
}
