#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int p, x, y, z;
        cin>>p>>x>>y>>z;
        int ma=max(x, y);
        int mi=min(x, y);
        long long int res;
        if (ma/2>=mi)
        {
            res=p*ma*ma;
        }
        else
        {
            res=p*(mi*2)*(mi*2);
        }
        cout<<res<<endl;
    }
    return 0;
}