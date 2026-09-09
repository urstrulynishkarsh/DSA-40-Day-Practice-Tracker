#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

int maxProfit(vector<int> prices)
{
    int maxprofit=0;
    int minprice=prices[0];
    for(int i=1;i<prices.size();i++)
    {
        int diff=prices[i]-minprice;
        maxprofit=max(maxprofit,diff);
        minprice=min(minprice,prices[i]);
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