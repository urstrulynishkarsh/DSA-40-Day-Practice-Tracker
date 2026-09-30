#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<numeric>
using namespace std;

int LIS(vector<int> &nums)
{
    
    int n=nums.size();
    if(n==0)
    {
        return 0;
    }
    vector<int> left(n);
    left[0]=1;
    vector<int> ans;
    ans.push_back(nums[0]);
    for(int i=1;i<n;i++)
    {
        if(nums[i]>ans.back())
        {
            ans.push_back(nums[i]);
        }
        else{
            int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            ans[index]=nums[i];
        }
        left[i]=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin()+1;
    }
    ans.clear();
    ans.push_back(nums[n-1]);
    vector<int> right(n);
    right[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        if(nums[i]>ans.back())
        {
            ans.push_back(nums[i]);
        }
        else{
            int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            ans[index]=nums[i];
        }
        right[i]=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin()+1;
    }

    int result=0;
    for(int i=0;i<left.size();i++)
    {
        if(left[i]>1 && right[i]>1)
        {
            result=max(result,left[i]+right[i]-1);
        }
    }
    return result;

        
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

    cout<<LIS(v);




}