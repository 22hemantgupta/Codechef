#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        int a[n+1];
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a, a+n);
        if (n>m)
        {
            int x=(n+m)/2;
            cout<<a[x]<<endl;
        }
        else
        {
            cout<<1000<<endl;
        }
    }
    return 0;
}