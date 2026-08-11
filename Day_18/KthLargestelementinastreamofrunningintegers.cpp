#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Kthlargest{
    public:
    int k;
    priority_queue<int,vector<int>,greater<int>>pq;

    Kthlargest(int k,vector<int> &nums)
    {
        this->k=k;
        for(int val:nums)
        {
            pq.push(val);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
    }
    int add(int value)
    {
        pq.push(value);
        if(pq.size()>k)
        {
            pq.pop();
        }
        return pq.top();
    }
};


int main()
{
    int k;
    int n;

    cout << "Enter k: ";
    cin >> k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Kthlargest obj(k, nums);

    int q;
    cout << "Enter number of values to add: ";
    cin >> q;

    cout << "Enter values: ";

    for(int i = 0; i < q; i++)
    {
        int value;
        cin >> value;

        cout << "Kth largest: " << obj.add(value) << endl;
    }

    return 0;
}