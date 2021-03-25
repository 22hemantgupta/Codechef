#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        int a[n+1][n+1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            int x;
            for(int j=1;j<=n;j++)
            {
                cout<<1<<" "<<i<<" "<<j<<" "<<i<<" "<<j<<endl;
                fflush(stdout);
                cin>>x;
                if(x==-1)
                {
                    break;
                }
                a[i][j]=x; 
            }
            if(x==-1)
            {
                break;
            }
        }
        cout<<2<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        int y;
        cin>>y;
        fflush(stdout);
        if(y==-1)
        {
            break;
        }
    }
    return 0;
}