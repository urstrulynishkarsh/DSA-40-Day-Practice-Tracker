#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int maxProfit(vector<int> prices)
{
   int maxprofit=0;
   for(int i=1;i<prices.size();i++)
   {
        if(prices[i]>prices[i-1])
        {
            maxprofit+=prices[i]-prices[i-1];
        }
   }
   return maxprofit;
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
    
    cout<<maxProfit(v);
    
    return 0;
}