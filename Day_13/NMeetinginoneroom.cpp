#include<iostream>
#include<vector>
using namespace std;

struct Meeting
{
    int s;
    int e;
    int pos;
};


vector<int> NMeetinginOneRoom(vector<int> &start, vector<int> &end, int n, int m)
{
    if(n==0)
    {
        return {};
    }
    vector<Meeting> meetings;
    for(int i=0;i<n;i++)
    {
        meetings.push_back({start[i],end[i],i+1});
    }
    auto lambda=[&](Meeting &a, Meeting &b){
        return a.e<b.e;
    };
    sort(meetings.begin(),meetings.end(),lambda);
    vector<int> ans;
    int lasttime=meetings[0].e;
    ans.push_back(meetings[0].pos);

    for(int i=1;i<n;i++)
    {
        if(meetings[i].s>lasttime)
        {
            ans.push_back(meetings[i].pos);
            lasttime=meetings[i].e;
        }
    }
    // remember this 
    sort(ans.begin(),ans.end());
    return ans;
}


int main()
{
    int n;
    cout<<"Enter the start size of array: ";
    cin>>n;


    vector<int> start(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>start[i];
    }

    int m;
    cout<<"Enter the start size of array: ";
    cin>>m;


    vector<int> end(m);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<m;i++)
    {
        cin>>end[i];
    }

    vector<int> result=NMeetinginOneRoom(start,end,n,m);
    for(int val:result)
        {
            cout<<val<<" ";
        }
        cout<<endl;

}