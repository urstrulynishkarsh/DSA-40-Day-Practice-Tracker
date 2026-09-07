#include<iostream>
using namespace std;

void printPrime(int n)
{
    if(n<=2)
    {
        return;
    }
    vector<bool> prime(n,true);
    prime[0]=prime[1]=false;
    for(int i=3;1LL*i*i<n;i+=2)
    {
        if(prime[i]==true)
        {
            for(int j=1LL*i*i;j<n;j+=i*2)
            {
                prime[j]=false;
            }
        }
    }
    cout<<2<<" ";
    for(int i=3;i<n;i+=2)
    {
        if(prime[i])
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;


    printPrime(n);
}