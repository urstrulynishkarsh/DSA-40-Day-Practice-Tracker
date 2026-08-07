#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

// O(N) time complexity
int atmost(vector<int> &v, int goal)
{
    int n=v.size();
    int i=0;
    int j=0;
    int ans=0;
    int odd=0;
    if(goal<0)
    {
        return 0;
    }
    while(j<n)
    {
        if(v[j]&1)
        {
            odd++;
        }
        while(odd>goal)
        {
            
            if(v[i]&1)
            {
                odd--;
            }
            i++;
        }
        ans+=j-i+1;
        j++;
    }
    return ans;
    


}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> v(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int k;
    cout<<"Enter the k  value: ";
    cin>>k;
    cout<<atmost(v,k)-atmost(v,k-1);
    
    return 0;
}