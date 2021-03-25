#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n, res=1;
        long long int mod = 1000000007;
        cin>>n;
        int b[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
        }
        for(int i=2;i<=n;i++)
        {
            bitset<30> pre(b[i-1]);
            bitset<30> cur(b[i]);
            for(int j=0;j<30;j++)
            {
                if(pre[j]==1 && cur[j]==1)
                res = (res*2)%mod;
                else if(cur[j] == 0 && pre[j] == 1)
                {
                    res=0;
                    break;
                }
            }
            if(res==0)
                break;
        }
        cout<<res<<endl;
    }
    return 0;
}