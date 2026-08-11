#include<iostream>
#include<vector>

using namespace std;

int Kthlargest(vector<int> &nums, int k)
{
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int val:nums)
    {
        pq.push(val);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    return pq.top();
}
int main()
{
    int n,k;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elemnent in the array: ";
    for(int i=0;i<n;i++)
    {   
        cin>>nums[i];
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<Kthlargest(nums,k);
    return 0;
}