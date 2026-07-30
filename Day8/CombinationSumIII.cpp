#include<iostream>
#include<vector>
using namespace std;


void combinationSumIII(vector<int> &nums,int index, int target, int count, int k, vector<vector<int> > &result,vector<int> &ans)
{
    if(count>k)
    {
        return;
    }
    if(count==k && target==0)
    {
        result.push_back(ans);
        return;
    }
    if(target<0)
    {
        return;
    }

    for(int i=index;i<nums.size();i++)
    {
        if(i>index && nums[i]==nums[i-1])
        {
            continue;
        }
        ans.push_back(nums[i]);
        combinationSumIII(nums,i+1,target-nums[i],count+1,k,result,ans);
        ans.pop_back();
    }
}

int main()
{
    int k;
    cout<<"Enter the k value: ";
    cin>>k;
    int n;
    cout<<"Enter the n value: ";
    cin>>n;


    vector<int> nums;
    for(int i=1;i<=9;i++)
    {
        nums.push_back(i);
    }
    int index=0;
    int target=n;
    int count=0;
    vector<vector<int> > result;
    vector<int> ans;
    combinationSumIII(nums,index,target,count,k,result,ans);
    for(auto V:result)
    {
        for(auto val:V)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;

    
}