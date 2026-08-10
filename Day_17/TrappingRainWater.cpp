#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<list>
using namespace std;

// O(N) time complexity
int trappingRainWater(vector<int> &nums)
{
    int n=nums.size();
    vector<int> left(n);
    vector<int> right(n);
    vector<int> water(n);

    left[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        left[i]=max(nums[i],left[i-1]);
    }
    right[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],nums[i]);
    }
    for(int i=0;i<n;i++)
    {
        water[i]=min(left[i],right[i])-nums[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=water[i];
    }
    return sum;

    

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
    cout<<trappingRainWater(v);
   
    
    return 0;
}