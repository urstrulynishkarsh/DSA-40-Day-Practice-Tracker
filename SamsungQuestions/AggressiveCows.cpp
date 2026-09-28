// 4. Aggressive Cows

// You're given N stall positions and C cows. Place the cows in stalls so that the minimum distance between any two cows is as large as possible.

// Return that largest minimum distance.

// Example 1

// Input:  N = 5, C = 3, stalls = [1, 2, 8, 4, 9]
// Output: 3

// Explanation: Put cows at 1, 4, and 8 (or 9). The smallest gap is 3.

// Example 2

// Input:  N = 5, C = 3, stalls = [1, 3, 5, 8, 10]
// Output: 4

// Explanation: Cows at 1, 5, 10. Gaps are 4 and 5, so the minimum is 4.


#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)

bool ispossible(vector<int> &nums,int m, int mid)
{
    int pos=nums[0];
    int c=1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]-pos>=mid)
        {
            c++;
            pos=nums[i];
        }
        if(c>=m)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    int C;
    cin>>C;
    vector<int> nums(N);
    rep(i,0,N)
    {
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int s=1;
    int e=nums[N-1]-nums[0];
    int ans=0;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(ispossible(nums,C,mid))
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<ans;


}