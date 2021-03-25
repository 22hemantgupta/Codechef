#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1][n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u-1][v-1]=w;
        a[v-1][u-1]=w;
    }
    if(n==2)
    {
        cout<<a[0][1]<<endl;
    }
    if(n==3)
    {
        int ab=min(a[0][1],a[0][2])+a[1][2];
        cout<<ab<<" "<<a[0][1]+a[0][2]<<endl;
    }
    if(n==4)
    {
        int p,q,r;
        r=a[0][1]+a[0][2]+a[0][3];
            int lo=min(min(a[0][1],a[0][2]),a[0][3]);
            if(a[1][3]!=0 && a[2][3]!=0 && a[1][2]!=0)
            {
                lo=lo+min(min(a[1][3]+a[1][2],(a[1][2]+a[2][3])),a[1][3]+a[2][3]);
            }
            else if(a[1][3]==0)
            {
                lo=lo+a[1][2]+a[2][3];
            }
            else if(a[2][3]==0)
            {
                lo=lo+a[1][3]+a[1][2];
            }
            else
            {
                lo=lo+a[1][3]+a[2][3];
            }
            p=lo;

q=q+min(min(a[0][1],a[0][2]),a[0][3]);
        if(a[1][3]!=0 && a[2][3]!=0 && a[1][2]!=0)
            {
                
                q=q+min(min(a[1][3],a[2][3]),a[1][2]);
            }
            else if(m==4)
            {
            if(a[1][3]!=0 )
            {
                q=q+a[0][1]+a[0][3]+a[1][3];
            }
            else if(a[2][3]!=0)
            {
                lo=lo+a[1][3]+a[1][2];
            }
            else
            {
                lo=lo+a[1][3]+a[2][3];
            }
            }
    }

    int ans[n];
    for(int i=0;i<=n-2;i++)
    {
        
    }
}