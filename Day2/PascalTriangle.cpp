#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
using namespace std;


vector<vector<int>> pascalTriangle(int numrows)
{
    vector<vector<int>> result(numrows);
    for(int i=0;i<numrows;i++)
    {
        result[i]=vector<int>(i+1,1);
        for(int j=1;j<i;j++)
        {
            result[i][j]=result[i-1][j]+result[i-1][j-1];
        }
    }
    return result;

}
int main()
{
    int n;
    cout<<"Enter the numrow: ";
    cin>>n;


    
    
    vector<vector<int>>result=pascalTriangle(n);
    for(auto V:result){
        for(int val:V)
            {
                cout<<val<<" ";
            }
            cout<<endl;
    }
    return 0;
}