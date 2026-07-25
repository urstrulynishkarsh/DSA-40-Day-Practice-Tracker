#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_set>
using namespace std;

// O(N) time complexity
int LongestConsecitiveSequence(vector<int> &v)
{
        unordered_set<int> st(v.begin(),v.end());
        int maxlength=0;

        for(int num:st)
        {
            if(st.find(num-1)==st.end())
            {
                int current=num;
                int length=1;
                while(st.find(current+1)!=st.end())
                {
                    current++;
                    length++;
                }
                maxlength=max(maxlength,length);
            }
        }
        return maxlength;


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
    cout<<LongestConsecitiveSequence(v);
    
    return 0;
}