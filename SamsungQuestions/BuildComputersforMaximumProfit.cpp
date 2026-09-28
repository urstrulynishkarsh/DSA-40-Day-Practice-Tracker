// 2. Build Computers for Maximum Profit (Two Problems Mixed.cpp – Part 1)

// You have D CPUs, E memory chips, and F boards. You can sell leftover CPUs for d each and leftover memory chips for e each. Boards can't be sold on their own.

// There are N computer configurations. Configuration i needs Di CPUs, Ei chips, and Fi boards, and sells for SPi.

// Rules:

// You may use at most 3 different configurations.
// You can build the same configuration any number of times.
// Whatever is left over is sold at the raw price.

// Return the maximum money you can make.

// Example 1

// Input:
// 1
// 10 10 10 2 1
// 1
// 1 2 2 3
// Output:
// Case #1
// 30

// Explanation: Building 5 computers gives 15, plus 5 leftover CPUs × 2 = 25. But selling everything raw gives 10×2 + 10×1 = 30, which is better.

// Example 2

// Input:
// 1
// 10 10 10 1 1
// 2
// 1 1 1 5
// 2 1 1 7
// Output:
// Case #1
// 50

// Explanation: Build config 1 ten times: 10 × 5 = 50.

// Constraints: 1 ≤ T ≤ 10, 1 ≤ D, E, F ≤ 100, 1 ≤ d, e ≤ 100000, 1 ≤ N ≤ 8.


#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;i++)
#define repe(i,a,n) for(int i=a;i<=n;i++)

int D,E,F,d,e;
int config;

struct configuration
{
    int D,E,F,SPI;
};

configuration m[9];

// dp[index][counta][D][E][F]
int dp[9][4][101][101][101];

int solve(int index, int counta, int D, int E, int F)
{
    // Base case
    if(index >= config || counta == 3)
    {
        // Sell leftover CPUs and memory
        return D*d + E*e;
    }

    // Already calculated
    if(dp[index][counta][D][E][F] != -1)
    {
        return dp[index][counta][D][E][F];
    }

    // Option 1: Don't use this configuration
    int ans = solve(index+1, counta, D, E, F);

    // Option 2:
    // Use this configuration i times
    int i = 1;

    while(true)
    {
        int newD = D - m[index].D * i;
        int newE = E - m[index].E * i;
        int newF = F - m[index].F * i;

        if(newD >= 0 && newE >= 0 && newF >= 0)
        {
            int current = 
                m[index].SPI * i +
                solve(index+1,
                      counta+1,
                      newD,
                      newE,
                      newF);

            ans = max(ans, current);

            i++;
        }
        else
        {
            break;
        }
    }

    return dp[index][counta][D][E][F] = ans;
}

int main()
{
    int T;
    cin >> T;

    repe(_cases,1,T)
    {
        cin >> D >> E >> F >> d >> e;

        cin >> config;

        rep(i,0,config)
        {
            cin >> m[i].D
                    >> m[i].E
                    >> m[i].F
                    >> m[i].SPI;
        }

        // Initialize DP
        memset(dp, -1, sizeof(dp));

        int answer = solve(0,0,D,E,F);

        cout << "Case #" << _cases << "\n";
        cout << answer << "\n";
    }

    return 0;
}
