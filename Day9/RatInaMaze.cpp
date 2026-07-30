#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

struct Choice
{
    /* data */
    char dname;
    int dx,dy;
};


bool isSolved(int x, int y, int n)
{
    return x==n-1 && y==n-1;
}

bool isValid(int x, int y,int n, vector<vector<int> > &matrix )
{
    return x>=0 && x<n && y>=0 && y<n && matrix[x][y]==1;
}
 
void solveRatMaze(int x, int y,vector<vector<int> > &matrix, int n,string &path,vector<string> &ans,vector<Choice> &choices)
{
    if(isSolved(x,y,n))
    {
        ans.push_back(path);
        return;
    }

    for(auto choice:choices)
    {
        int newX=x+choice.dx;
        int newY=y+choice.dy;
        if(isValid(newX,newY,n,matrix))
        {
            matrix[x][y]=0;
            path.push_back(choice.dname);
            solveRatMaze(newX,newY,matrix,n,path,ans,choices);
            matrix[x][y]=1;;
            path.pop_back();

        }
    }
}
int main()
{
    int n,m;
    cout<<"Enter the row and col: ";
    cin>>n>>m;
    vector<vector<int> >matrix(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    vector<string> ans;
    string path="";
    vector<Choice> choices={{'U',-1,0},{'D',1,0},{'L',0,-1},{'R',0,1}};
    if(matrix[0][0]==1)
    {
        solveRatMaze(0,0,matrix,n,path,ans,choices);
    }
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}