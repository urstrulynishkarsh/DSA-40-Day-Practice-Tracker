#include<iostream>
#include<vector>
using namespace std;

int minPlatform(vector<int> &arrival, vector<int> &dept, int n)
{
    sort(arrival.begin(),arrival.end());
    sort(dept.begin(),dept.end());
    int i=0;
    int j=0;
    int platform=0;
    int ans=0;
    while(i<n && j<n)
    {
        if(arrival[i]<=dept[j])
        {
            platform++;
            ans=max(ans,platform);
            i++;
        }
        else{
            platform--;
            j++;
        }
    }
    return ans;
}





int main()
{
    int n;
    cout<<"Enter the start size of array: ";
    cin>>n;


    vector<int> arrival(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arrival[i];
    }

  


    vector<int> dept(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>dept[i];
    }

    cout<<minPlatform(arrival,dept,n);
    return 0;

}