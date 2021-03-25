#include <bits/stdc++.h> 
using namespace std; 
vector<long long int> v;
void SieveOfEratosthenes()
{
    long long int k=100000;
    bool prime[k+1];
    memset(prime, true, sizeof(prime)); 
    for (long long int p=2; p<=k; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (long long int i=p*p; i<=k; i += p) 
                prime[i] = false; 
        } 
    } 
    for (long long int p=2; p<=k; p++)
    { 
       if (prime[p])
       { 
           v.push_back(p);
       }
    }
}
long long int result(long long int n)
{
    long long int count=0;
    long long int res=0,y=n;
    for(int i=0;i<v.size();i++)
    {
        count=0;
        if(v[i]>sqrt(y))
           break;
        while(n%v[i]==0 && n!=1)
        {
            n=n/v[i];
            count++;
        }
        res = res + count;
    }
    if(n>2)
    {
        res = res + 1;
    } 
    return res;
}
int main()
{
    int T;
    cin>>T;
    SieveOfEratosthenes();
    while(T--)
    {
        long long int x,k,r=0;
        cin>>x>>k;
        if(k<=x)
        {
            r = result(x);
        if(r>=k)
        {
            int l=1;
            cout<<l<<endl;
        } 
        else
        {
            int l=0;
            cout<<l<<endl;
        }
        }
        else
        {
            int l=0;
            cout<<l<<endl;
        }
    }
    return 0;
}