#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long int n,p;
        cin>>n>>p;
        long int a[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long int r[n+1];
        long int count=0,co=0,k;
        for(int i=1;i<=n;i++)
        {
            r[i]=p%a[i];
            if(r[i]!=0 && co==0)
            {
                k=i;
                co++;
            }
            if(r[i]==0)
            {
                count++;
            }
        }
        long int c[n+1]={0};
        long int v[n+1]={0};
        //long int rem=p;
        long int g=0;
        //if(count == n)
       // {
            long int re=p;
            bool flag=false;
            long int s=0;
            for(int i=n;i>=1;i--)
            {
                if(re%a[i]==0)
                {
                    v[i]=re/a[i]-1;
                    re=re-(v[i]*a[i]);
                }
                else
                {
                    v[i]=re/a[i];
                    s=i;
                    re=re-(v[i]*a[i]);;
                    flag=true;
                }
                }
                else
                {
                    g=i;
                }
                
            }
            if(s!=0)
                v[s]++;
            if(flag==false)
            {
                if(g!=0)
                {
                    c[g]++;
                    cout<<"YES";
                    for(int i=1;i<=n;i++)
                    {
                        cout<<c[i];
                    }
                }
                else
                {
                    cout<<"NO";
                }
            }
            else
                {
                    cout<<"YES";
                    for(int i=1;i<=n;i++)
                    {
                        cout<<v[i];
                    }
                }
        //}
       /* else
        {
            for(int i=n;i>=1;i--)
            {
                if(r[i]!=0)
                {
                    c[i]=rem/a[i];
                    rem=rem%a[i];
                }
            }
            c[k]++;
            cout<<"YES";
            for(int i=1;i<=n;i++)
            {
                cout<<c[i];
            }
            //cout<<endl;
        }*/
        cout<<endl;
    }
    return 0;
}