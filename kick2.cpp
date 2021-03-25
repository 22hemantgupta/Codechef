#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int l=1;
    while(T--)
    {
        int n,d;
        cin>>n>>d;
        int a[n+1];
        int div[n+1];
        int res[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            div[i]=d/a[i];
            res[i]=div[i]*a[i];
        }
        int ans=0;
        if(n==1)
        {
            ans=res[0];
        }
        else
        {
        for(int i=0;i<n;i++)
        {
        if(res[i]<res[0])
        {
            int r=res[0]-res[i];
            int y=(r/a[0])+1;
            ans=res[0]-(a[0]*y);
            if(ans<res[0])
            res[0]=ans;
        }
        }
        }
        cout<<"Case #"<<l<<": "<<res[0]<<endl;
        ++l;
    }
    return 0;
}