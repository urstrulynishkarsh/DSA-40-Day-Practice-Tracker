#include<iostream>
#include<vector>
using namespace std;


int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    auto lambda=[&](vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    };
    sort(intervals.begin(),intervals.end(),lambda);
    int n=intervals.size();
    int count=1;
    int lasttime=intervals[0][1];
    for(int i=1;i<=n-1;i++)
    {
        if(intervals[i][0]>=lasttime)
        {
            count++;
            lasttime=intervals[i][1];
        }
    }
    return n-count;
}
int main()
{
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals;

    cout << "Enter each interval (start end):\n";
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        intervals.push_back({start, end});
    }

    cout<<eraseOverlapIntervals(intervals);
}