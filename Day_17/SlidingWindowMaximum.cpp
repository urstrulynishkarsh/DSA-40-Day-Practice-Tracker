#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
#include<list>
using namespace std;

// O(N) time complexity
vector<int> maxSlidingWindow(vector<int> &v, int k)
{
    int n=v.size();
    list<int> l1;
    int i=0;
    int j=0;
    vector<int> ans;
    while(j<n)
    {
        while(!l1.empty() && l1.back()<v[j])
        {
            l1.pop_back();
        }
        l1.push_back(v[j]);
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1==k)
        {
            ans.push_back(l1.front());
            if(l1.front()==v[i])
            {
                l1.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;

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
    int k;
    cout<<"Enter the k  value: ";
    cin>>k;
    vector<int> result=maxSlidingWindow(v,k);
    for(int val:result)
    {
        cout<<val<<" ";
    }
    
    return 0;
}