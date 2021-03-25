#include<bits/stdc++.h>
#include<map>
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
        bool c[n+1];
        for(int i=0;i<n;i++)
        {
            c[i]=false;
        }
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        map<int, int> map1;
        map<int, int> map2;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                map1[a[i]]=i;
                map2[b[i]]=i;
            }
            else
            {
                c[i]=true;
            }            
        }
        int count=0;
        int d[k][3];
        int j=0;
        auto z=map1.begin();
        z++;
        for(auto it=map1.begin();it!=map1.end();it++)
        {
            if(c[it->second]==false)
            {
                int x=map2[it->first];
                int temp1=a[x];
                int y=map2[temp1];
                a[x]=it->first;
                c[x]=true;
                d[j][0]=x+1;
                if(it->second==y)
                {
                    while(c[z->second]==true)
                    {
                        z++;
                    }
                    if(c[z->second]==false)
                    {
                    a[z->second]=temp1;
                    //c[z->second]=true;
                    int temp2=z->first;
                    d[j][1]=temp1;
                    d[j][2]=temp2;
                    a[it->second]=temp2;
                    }
                    else
                    {
                        count=-1;
                    }                            
                }
                else
                {
                d[j][1]=y+1;
                int temp2=a[y];
                d[j][2]=it->second+1;
                a[y]=temp1;
                c[y]=true;
                a[it->second]=temp2;
                }
                j++;
                z++;
            }
        }
        int gin=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                gin++;
            }
        }
        if(count==-1 && j>k)
        {
            cout<<count<<endl;
        }
        else if(gin>0)
        {
            cout<<"-1"<<endl;
        }
        else
        {    
        cout<<j<<endl;
        for(int m=0;m<j;m++)
        {
            cout<<d[m][0]<<" "<<d[m][1]<<" "<<d[m][2]<<endl;
        }
        }
    }
    return 0;
}