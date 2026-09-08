#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;


int maximumPoints(vector<vector<int> > &mat)
{
     int running=mat[0][0];
        int fighting=mat[0][1];
        int learning=mat[0][2];
        
        for(int i=1;i<mat.size();i++)
        {
            int newrunning=mat[i][0]+max(fighting,learning);
            int newfighting=mat[i][1]+max(running,learning);
            int newlearning=mat[i][2]+max(fighting,running);
            running=newrunning;
            fighting=newfighting;
            learning=newlearning;
        }
        return max({running,fighting,learning});
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
    
    cout<<maximumPoints(matrix);
    return 0;
}