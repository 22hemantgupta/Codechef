#include<bits/stdc++.h>
using namespace std;
void SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    vector<vector<int> > v(10000);
    int k=0;
    v[k].push_back(1);
    k++;
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        {
            v[k].push_back(p);   
            for (int i=p*p; i<=n; i += p)
            {
                if(prime[i] == true)
                {
                    v[k].push_back(i);
                } 
                prime[i] = false;
            }
            k++; 
        } 
    }
    for (int i = 0; i < v.size(); i++) { 
        for (int j = 0; j < v[i].size(); j++) 
            cout << v[i][j] << " "; 
        cout << endl; 
    } 
    int d=v[1].size();
    cout<<d<<endl;
    int a[10000];
    int b[10000];
    for(int i=0;i<v.size();i++)
    {
        b[i]=v[i].size();
    }
    int j=0;
    while(d>0)
    {
        for(int i=0;i<v.size();i++)
        {
            if(b[i]>0)
            {
                a[j]=a[j]+1;
                b[i]--;
            }
        }
        j++;
        d--;
    }
    int m=0;
    while(m<v[1].size())
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<a[m]<<" ";
            if(v[i][m]>0)
            {
                cout<<v[i][m]<<" ";
            }
        }
        m++;
        cout<<endl;
    }   
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n;
        cin>>n;
        SieveOfEratosthenes(n);
    }
    return 0;
}