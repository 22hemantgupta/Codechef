#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        int a[n+1];
        int b[n+1];
        int q[n+1];
        int p[n+1];
        int r[n+1][3];
        int j=0;
        int s[n+1];
        int l=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
            q[i]=a[i];
            p[a[i]]=i;
        } 
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(p[i]==b[i] && b[i]!=i)
            {
                s[l]=i;
                l++;
                s[l]=p[i];
          
                b[p[i]]=0;
                l++;
            }
        }
        //cout<<l<<" ";
        /*for(int i=1;i<l;i++)
        {
            cout<<s[i]<<" ";
        }*/
        if((l-1)%4==2)
        {
        /*    l=l-2;
        for(int i=1;i<l;i=i+4)
        {
            a[s[i]]=s[i];
            a[s[i+1]]=s[i+1];
            a[s[i+2]]=s[i+2];
            a[s[i+3]]=s[i+3];
            p[s[i]]=s[i];
            p[s[i+1]]=s[i+1];
            p[s[i+2]]=s[i+2];
            p[s[i+3]]=s[i+3];
            r[j][0]=s[i];
            r[j][1]=s[i+2];
            r[j][2]=s[i+1];
            j++;
            r[j][0]=s[i+2];
            r[j][1]=s[i+1];
            r[j][2]=s[i+3];
            j++;          
        }
        s[1]=s[l];
        s[2]=s[l+1];
        l=3;*/
        for(int i=1;i<n-1;i++)
        {
            int u=i;
            if(a[i]!=i)
            {
                if(p[i]!=a[i] && p[i]!=i+1)
                {
                int temp1=a[i];
                int o=p[i];
                a[i]=i;
                q[i]=a[i];
                p[i]=i;
                p[temp1]=temp1;
                int temp2=a[temp1];
                a[temp1]=temp1;
                q[temp1]=a[temp1];
                p[temp2]=o;
                a[o]=temp2;
                q[o]=a[o];
                r[j][0]=i;
                r[j][1]=temp1;
                r[j][2]=o;
                j++;
                }
                else if(p[i]==a[i])
                {
                   /* u++;
                    while((a[u]==u || a[u]==i) && u<=n-2)
                    {
                        u++;
                    }
                if(a[u]!=u && a[u]!=i)
                {
                int temp1=a[i];
                int o=p[i];
                a[i]=i;
                p[i]=i;
                p[temp1]=u;
                int temp2=a[u];
                p[temp2]=o;
                a[u]=temp1;
                a[o]=temp2;
                r[j][0]=i;
                r[j][1]=u;
                r[j][2]=o;
                j++;
                }*/
                if(p[i]==q[i])
                {
                    s[l]=i;
                    l++;
                    s[l]=p[i];
                    q[p[i]]=0;
                    l++;
                }
                }  
                else if(p[i]!=a[i] && p[i]==i+1)
                {
                    u=u+2;
                    while((a[u]==u || a[u]==i) && u<=n-2 )
                    {
                        u++;
                    }
                if(a[u]!=u && a[u]!=i)
                {
                int temp1=a[i];
                int o=p[i];
                p[a[i]]=u;
                a[i]=i;
                p[i]=i;
                int temp2=a[u];
                p[a[u]]=o;
                a[u]=temp1;
                a[o]=temp2;
                r[j][0]=i;
                r[j][1]=u;
                r[j][2]=o;
                j++;
                }
                }     
            }
        }
        if(a[n]==p[n])
        {
            s[l]=p[n];
            l++;
            s[l]=a[n];
            l++;
        }
        if((l-1)%4==2)
        {
            count=-1;
        }
        else
        {    
        for(int i=1;i<l;i=i+4)
        {
            a[s[i]]=s[i];
            a[s[i+1]]=s[i+1];
            a[s[i+2]]=s[i+2];
            a[s[i+3]]=s[i+3];
            p[s[i]]=s[i];
            p[s[i+1]]=s[i+1];
            p[s[i+2]]=s[i+2];
            p[s[i+3]]=s[i+3];
            r[j][0]=s[i];
            r[j][1]=s[i+2];
            r[j][2]=s[i+1];
            j++;
            r[j][0]=s[i+2];
            r[j][1]=s[i+1];
            r[j][2]=s[i+3];
            j++;          
        }
        }
        }
        else
        {
        for(int i=1;i<l;i=i+4)
        {
            a[s[i]]=s[i];
            a[s[i+1]]=s[i+1];
            a[s[i+2]]=s[i+2];
            a[s[i+3]]=s[i+3];
            p[s[i]]=s[i];
            p[s[i+1]]=s[i+1];
            p[s[i+2]]=s[i+2];
            p[s[i+3]]=s[i+3];
            r[j][0]=s[i];
            r[j][1]=s[i+2];
            r[j][2]=s[i+1];
            j++;
            r[j][0]=s[i+2];
            r[j][1]=s[i+1];
            r[j][2]=s[i+3];
            j++;          
        }
        for(int i=1;i<n-1;i++)
        {
            int u=i;
            if(a[i]!=i)
            {
                if(p[i]!=a[i] && p[i]!=i+1)
                {
                int temp1=a[i];
                int o=p[i];
                a[i]=i;
                p[i]=i;
                p[temp1]=temp1;
                int temp2=a[temp1];
                a[temp1]=temp1;
                p[temp2]=o;
                a[o]=temp2;
                r[j][0]=i;
                r[j][1]=temp1;
                r[j][2]=o;
                j++;
                }
                else if( p[i]==a[i] && p[i]!=i+1)
                {
                    u++;
                    while((a[u]==u || a[u]==i) && u<=n-2)
                    {
                        u++;
                    }
                if(a[u]!=u && a[u]!=i)
                {
                int temp1=a[i];
                int o=p[i];
                a[i]=i;
                p[i]=i;
                p[temp1]=u;
                int temp2=a[u];
                p[temp2]=o;
                a[u]=temp1;
                a[o]=temp2;
                r[j][0]=i;
                r[j][1]=u;
                r[j][2]=o;
                j++;
                }
                }  
                else
                {
                    u=u+2;
                    while((a[u]==u || a[u]==i) && u<=n-2 )
                    {
                        u++;
                    }
                if(a[u]!=u && a[u]!=i)
                {
                int temp1=a[i];
                int o=p[i];
                p[a[i]]=u;
                a[i]=i;
                p[i]=i;
                int temp2=a[u];
                p[a[u]]=o;
                a[u]=temp1;
                a[o]=temp2;
                r[j][0]=i;
                r[j][1]=u;
                r[j][2]=o;
                j++;
                }
                }     
            }
        }
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=i)
            count++;
        }
        if(count==0 && j<=k)
        {
            cout<<j<<endl;
            for(int i=0;i<j;i++)
            {
                cout<<r[i][0]<<" "<<r[i][1]<<" "<<r[i][2]<<endl;
            }
        }
        else
        {
            int w=-1;
            cout<<w<<endl;
        }
    }
    return 0;
}
        