#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int b[1001]={0};
        for(int i=1;i<=n;i++)
        {
            b[a[i]]++;
            if(i+1<=n && a[i]==a[i+1])
            {
                i=i+1;
            }
        }
        int ans=0, mfreq=0;
        for(int i=1; i<=1000; ++i)
        if(b[i]>mfreq)
        {
            ans=i; mfreq=b[i]; 
        }
        cout<<ans<<"\n";
    }
    return 0;
}