#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;


int upperBound(vector<int>  &v, int n,int target)
{
    int s=0;
    int e=n-1;
    int ans=v.size();
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(v[mid]>target)
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int countsmallequal(vector<vector<int> > &matrix, int n, int m, int target)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        count+=upperBound(matrix[i],m,target);
    }
    return count;
}

int median(vector<vector<int> > &matrix, int n, int m)
{
    int low = matrix[0][0];
    int high = matrix[0][m-1];
    for(int i=0;i<n;i++)
    {
        low=min(low,matrix[i][0]);
        high=max(high,matrix[i][m-1]);
    }

    int req=n*m/2;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int smallequal=countsmallequal(matrix,n,m,mid);
        if(smallequal<=req)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
    

    
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
    cout<<median(matrix,n,m);
    return 0;
}