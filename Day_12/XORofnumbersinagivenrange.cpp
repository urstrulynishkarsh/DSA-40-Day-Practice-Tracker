#include<iostream>
using namespace std;

int find(int n)
    {
        if(n%4==1)
        {
            return 1;
        }
        else if(n%4==2)
        {
            return n+1;
        }
        else if(n%4==3)
        {
            return 0;
        }
        else{
            return n;
        }
    }

 int findXOR(int l, int r) {
        // code here
        return find(l-1)^find(r);
    }
int main()
{
    int l,r;
    cout<<"Enter the value of l and r: ";
    cin>>l>>r;
    cout<<findXOR(l,r);
}