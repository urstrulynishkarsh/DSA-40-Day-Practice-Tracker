#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;


class MinStack{
    public:
    vector<pair<int,int> >st;

    MinStack()
    {

    }
    void push(int value)
    {
        if(st.empty())
        {
            st.push_back({value,value});
        }
        else{
            pair<int,int> p;
            p.first=value;
            p.second=min(value,st.back().second);
            st.push_back(p);
        }
    }

    void pop()
    {
        st.pop_back();
    }
    int top()
    {
        return st.back().first;
    }
    int getmin()
    {
        return st.back().second;
    }

};


int main()
{
    MinStack st;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    while (n--)
    {
        int choice;
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Get Min\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            st.push(value);
        }
        else if (choice == 2)
        {
            st.pop();
        }
        else if (choice == 3)
        {
            cout << "Top: " << st.top() << endl;
        }
        else if (choice == 4)
        {
            cout << "Minimum: " << st.getmin() << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}