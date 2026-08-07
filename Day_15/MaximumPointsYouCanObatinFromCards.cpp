#include<iostream>
#include<vector>
using namespace std;

int MaximumPoint(vector<int> &nums, int k)
{
    int n=nums.size();
    int leftsum=0;
    for(int i=0;i<k;i++)
    {
        leftsum+=nums[i];
    }
    int maxi=leftsum;
    int rightsum=0;
    for(int i=0;i<k;i++)
    {
        leftsum-=nums[k-1-i];
        rightsum+=nums[n-1-i];
        maxi=max(maxi,leftsum+rightsum);
    }
    return maxi;
}
int main()
{
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<MaximumPoint(nums,k);


}