// 3. Count Colored Paper Pieces (Two Problems Mixed.cpp – Part 2)

// You have an N × N paper (N = 2^K, 1 ≤ K ≤ 7). Each cell is 0 (white) or 1 (blue).

// Cutting rule: if a piece isn't entirely one color, cut it into 4 equal squares. Repeat on each square until every piece has a single color.

// Return the number of white pieces and blue pieces.

// Example

// Input:
// 4
// 1 1 0 0
// 1 1 0 0
// 0 0 1 0
// 0 0 0 1
// Output:
// 4
// 3

// Explanation: Top-left is all blue (1 piece), top-right is all white (1), bottom-left is all white (1). Bottom-right is mixed, so it's cut into 4 single cells: 2 blue and 2 white. White = 4, Blue = 3.


// 427. Construct Quad Tree

#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;i++)

int white=0;
int blue=0;

vector<vector<int>>paper;

void solve(int i, int j, int size)
{
    int color=paper[i][j];
    bool same=true;

    rep(x,i,i+size)
    {
        rep(y,j,j+size)
        {
            if(paper[x][y]!=color)
            {
                same=false;
                break;
            }
        }
        if(!same)
        {
            break;
        }
    }
    if(same)
    {
        if(color==0)
        {
            white++;
        }
        else{
            blue++;
        }
        return;
    }
    int half=size/2;
    solve(i,j,half);
    solve(i,j+half,half);
    solve(i+half,j,half);
    solve(i+half,j+half,half);
}

int main()
{
    int N;
    cin>>N;

    paper.resize(N,vector<int>(N));

    rep(i,0,N){
        rep(j,0,N)
        {
            cin>>paper[i][j];
        }
    }
    solve(0,0,N);
    cout<<white<<" "<<blue<<"\n";
    return 0; 
}