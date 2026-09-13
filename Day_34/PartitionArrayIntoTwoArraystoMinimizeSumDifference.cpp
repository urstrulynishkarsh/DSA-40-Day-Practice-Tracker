#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<algorithm>
#include<climits>
#include<numeric>
using namespace std;

int partitionArray(vector<int> &nums)
{
    int N=nums.size();
    int n1=N/2;
    int n2=N-n1;
    int S=accumulate(nums.begin(),nums.end(),0);
    unordered_map<int,vector<int>>sumleft;
    unordered_map<int,vector<int>>sumright;
    for(int mask=0;mask<(1<<n1);mask++)
    {
        int s=0;
        int count=0;
        for(int i=0;i<n1;i++)
        {
            if(mask&(1<<i))
            {
                s+=nums[i];
                count++;
            }
        }
        sumleft[count].push_back(s);
    }
    for(int mask=0;mask<(1<<n2);mask++)
    {
        int s=0;
        int count=0;
        for(int i=0;i<n2;i++)
        {
            if(mask&(1<<i))
            {
                s+=nums[n1+i];
                count++;
            }
        }
        sumright[count].push_back(s);
    }
    for(int count=0;count<=n2;count++)
    {
        sort(begin(sumright[count]),end(sumright[count]));
    }
    int mini=INT_MAX;
    for(int k=0;k<=n1;k++)
    {
        int m=N/2-k;
        for(int leftsubsum:sumleft[k])
        {
            int need=(S-2*leftsubsum)/2;
            int low=lower_bound(begin(sumright[m]),end(sumright[m]),need)-begin(sumright[m]);

            if(low<sumright[m].size())
            {
                int rightsubsum=sumright[m][low];
                mini=min(mini,abs(2*(leftsubsum+rightsubsum)-S));
            }
            if(low-1>=0)
            {
                int rightsubsum=sumright[m][low-1];
                mini=min(mini,abs(2*(leftsubsum+rightsubsum)-S));
            }
        }
    }
    return mini;


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
    
    cout<<partitionArray(v);
    
    return 0;
}