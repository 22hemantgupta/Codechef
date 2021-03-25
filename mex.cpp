#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n+1];
        set<int> v;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<m)
            {
                v.insert(a[i]);
            }
        }
        int j=1;
        int count=0;
        int flag=0;
        for(auto it=v.begin();it!=v.end();it++)
        {
            if(*it!=j)
            {
                flag=1;
                break;
            }
            else
            {
                j++;
            }
                    
        }
        if(flag==1)
        {
            cout<<-1<<endl;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(a[i]==m)
                count++;
            }
            cout<<n-count<<endl;
        } 
    }
    return 0;
}