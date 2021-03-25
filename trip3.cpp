#include<bits/stdc++.h>
using namespace std;
int next(deque<int>& d,int *p,int i)
{
    if(d.empty())
    return -1;
    int r=d.front();
    d.pop_front();
    if(i!=0 && p[i]==r || r==p[r] || r==i)
    {
        return next(d,p,i);
    }
    return r;
}
int next1(deque<int>& f,int *q,int i)
{
    if(f.empty())
    return -1;
    int r=f.front();
    f.pop_front();
    if(i!=0 && q[i]==r || r==q[r] || r==i)
    {
        return next1(f,q,i);
    }
    return r;
}
void tripsort(int i,int j,int k,int *a,int *p,deque<int>& d,int n,vector<bool>& v)
{
    int temp=a[i];
    a[i]=a[k];
    p[a[k]]=i;
    if(i==a[a[k]] && a[k]!=i)
        {
            if(v[a[k]]==false)
            {
                d.push_back(a[k]);
                d.push_back(p[a[k]]);
                v[a[k]]=true;
                v[p[a[k]]]=true;
            }
        }
    if(a[k]!=i && a[a[k]]!=i)
        d.push_front(a[k]);

    a[k]=a[j];
    p[a[j]]=k;
    if(k==a[a[j]] && a[j]!=k)
    {
        if(v[a[j]]==false)
        {
             d.push_back(a[j]);
             d.push_back(p[a[j]]);
             v[a[j]]=true;
             v[p[a[j]]]=true;
        }
    }
    if(a[j]!=k && a[a[j]]!=k)
        d.push_front(a[j]);

    a[j]=temp;
    p[temp]=j;
    if(temp!=j && j==a[temp])
    {
        if(v[temp]==false)
        {
            d.push_back(temp);
            d.push_back(p[temp]);
            v[temp]=true;
            v[p[temp]]=true;
        }
    }
    if(temp!=j && a[temp]!=j)
        d.push_front(temp);

   /* for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;*/
}
void tripsort1(int i,int j,int k,int *b,int *q,deque<int>& f,int n,vector<bool>& u)
{
    int temp=b[i];
    b[i]=b[k];
    q[b[k]]=i;
    if(i==b[b[k]] && b[k]!=i)
    {
        if(u[b[k]]==false)
        {
            f.push_front(b[k]);
            f.push_front(q[b[k]]);
            u[b[k]]=true;
            u[q[b[k]]]=true;
        }
    }
    if(b[k]!=i && b[b[k]]!=i)
        f.push_back(b[k]);

    b[k]=b[j];
    q[b[j]]=k;
    if(k==b[b[j]] && b[j]!=k)
    {
        if(u[b[j]]==false)
        {
            f.push_front(b[j]);
            f.push_front(q[b[j]]);
            u[b[j]]=true;
            u[q[b[j]]]=true;
        }
    }
    if(b[j]!=k && b[b[j]]!=k)
        f.push_back(b[j]);

    b[j]=temp;
    q[temp]=j;
    if(temp!=j && j==b[temp])
    {
        if(u[temp]==false)
        {
            f.push_front(temp); 
            f.push_front(q[temp]);
            u[temp]=true;
            u[q[temp]]=true;
        }   
    }
    if(temp!=j && b[temp]!=j)
        f.push_back(temp);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        deque<int> d;
        int n,k;
        cin>>n>>k;
        int a[n+1];
        int b[n+1];
        int p[n+1];
        int q[n+1];
        int r[n+1][3];
        int s[n+1][3];
        int j=0;
        int l=0;
        int count=0;
        vector<bool> v(n,false);
        vector<bool> u(n,false);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
            p[a[i]]=i;
            q[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=i)
            {
                if(p[p[a[i]]]==a[i])
                {
                    if(v[a[i]]==false)
                    {
                        d.push_back(a[i]);
                        d.push_back(p[a[i]]);
                        v[a[i]]=true;
                        v[p[a[i]]]=true;
                    }
                }
                else
                {
                    d.push_front(a[i]);
                }
            }
        }
        //int fail=0;
        while(!d.empty())
        {
            int x,ix,iix;
            x=next(d,p,0);
            if(x==-1)
            {
             //   fail=1;
                break;
            }
            ix=p[x];
            iix=p[ix];
            if(x==iix)
            {
                if(x<ix)
                {
                    iix=next(d,p,x);
                    if(iix==-1)
                    {
                      //  fail=1;
                        break;
                    }
                }
                else
                {
                    x=next(d,p,iix);
                    if(x==-1)
                    {
                        //fail=1;
                        break;
                    }
                }    
            }
            tripsort(ix,x,iix,a,p,d,n,v); 
           //cout<<ix<<" "<<x<<" "<<iix<<endl;
            r[j][0]=x;
            r[j][1]=iix;
            r[j][2]=ix;
            j++;
        }
       // cout<<j;
        for(int i=1;i<=n;i++)
        {

            //cout<<a[i]<<endl;
            if(a[i]!=i)
                count++;
        }
        if(j>k && count==0)
        {
            deque<int> f;
            for(int i=1;i<=n;i++)
            {
                if(b[i]!=i)
            {
                if(q[q[b[i]]]==b[i])
                {
                    if(u[b[i]]==false)
                    {
                        f.push_front(b[i]);
                        f.push_front(q[b[i]]);
                        u[b[i]]=true;
                        u[q[b[i]]]=true;
                    }
                }
                else
                {
                    f.push_back(b[i]);
                }
            }
            }
            //int fail1=0;
            while(!f.empty())
           {
            int x,ix,iix;
            x=next1(f,q,0);
            if(x==-1)
            {
               // fail1=1;
                break;
            }
            ix=q[x];
            iix=q[ix];
            if(x==iix)
            {
                if(x<ix)
                {
                    iix=next1(f,q,x);
                    if(iix==-1)
                    {
                      //  fail1=1;
                        break;
                    }
                }
                else
                {
                    x=next1(f,q,iix);
                    if(x==-1)
                    {
                        //fail1=1;
                        break;
                    }
                }    
            }
            tripsort1(ix,x,iix,b,q,f,n,u);
            s[l][0]=x;
            s[l][1]=iix;
            s[l][2]=ix;
            l++;
           }
           int count1=0;
            for(int i=1;i<=n;i++)
            {
                if(b[i]!=i)
                    count1++;
            }
            //l=min(l,j);   
            if(l<=k && count1==0)
            {
                j=l;
                for(int z=0;z<j;z++)
                {
                    r[z][0]=s[z][0];
                    r[z][1]=s[z][1];
                    r[z][2]=s[z][2];
                }
            }
        }
        /*for(int i=1;i<=n;i++)
        {
            if(b[i]!=i)
            count++;
        }*/   
        if(count == 0 && j<=k)
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