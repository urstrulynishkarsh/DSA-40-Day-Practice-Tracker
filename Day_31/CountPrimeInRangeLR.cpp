#include<iostream>
using namespace std;


void countPrime(int &L, int &R)
{
    vector<bool> prime(R+1,true);
    prime[0]=prime[1]=false;
    for(int i=2;1LL*i*i<=R;i++)
    {
        if(prime[i])
        {
            for(long long j=1LL*i*i;j<=R;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    for(int i=max(L,2);i<=R;i++)
    {
        if(prime[i])
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    int L,R;
    cout<<"Enter the value of L and R: ";
    cin>>L>>R;
    countPrime(L,R);
}