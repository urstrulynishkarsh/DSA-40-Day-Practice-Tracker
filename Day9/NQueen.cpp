#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
using namespace std;
unordered_map<int,bool>rowcheck,lowerdiagonalcheck,upperdiagonalcheck;

bool isSafe(int &row, int &col)
{
    if(rowcheck[row]==true)
    {
        return false;
    }
    if(lowerdiagonalcheck[row+col]==true)
    {
        return false;
    }
    if(upperdiagonalcheck[row-col]==true)
    {
        return false;
    }
    return true;
}


void printsolution(vector<vector<char> > &board, int n,vector<vector<string> > &result)
{
    vector<string> ans;
    for(int i=0;i<n;i++)
    {
        string output;
        for(int j=0;j<n;j++)
        {
            output.push_back(board[i][j]);
        }
        ans.push_back(output);
    }
    result.push_back(ans);
}


void solve(vector<vector<char> > &board, int n, int col,vector<vector<string> > &result)
{
    if(col>=n)
    {
        printsolution(board,n,result);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col))
        {
            board[row][col]='Q';
            rowcheck[row]=lowerdiagonalcheck[row+col]=upperdiagonalcheck[row-col]=true;
            solve(board,n,col+1,result);
            board[row][col]='.';
            rowcheck[row]=lowerdiagonalcheck[row+col]=upperdiagonalcheck[row-col]=false;

        }
    }
}


int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<vector<char> >board(n,vector<char>(n,'.'));
    vector<vector<string> >result;
    int col=0;
    solve(board,n,col,result);
    for(auto str:result)
    {
        for(auto s:str)
        {
            cout<<s<<" ";
        }
        cout<<endl;

    }

}