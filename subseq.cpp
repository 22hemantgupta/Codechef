#include<bits/stdc++.h>
using namespace std;
long long int result(long long int n)
{
    long long int re = (long long int)(n*(n+1))/2;
    return re;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        long long int a[n+1];
        vector<int> v;
        long long int count2,ans;
        ans=0LL;
        count2=0;
        long long int r[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            r[i]=(a[i]%4);
            if(r[i]==2)
            {
                v.push_back(i);
                count2++;
            }
            else if(r[i]==0)
            {
                v.push_back(i);
            }
        }
        if(count2==0)
        {
            long long int be=result(n);
            cout<<be<<endl;
            continue;
        }
        if(v.size()==1)
        {
            if(count2==1)
            {
                ans=(long long int)(ans+result(v[0]-1)+result(n-v[0]));
                cout<<ans<<endl;
            }
           else
            {
                ans+=result(n);
                cout<<ans<<endl;
            }
            continue;
        }
        for(int i=0;i<v.size();i++)
        {
            if(r[v[i]]==0)
            {
                continue;
            }
            if( i == (v.size()-1))
            {
                long long int x=n-v[i-1];
                ans=(long long int)(ans+result(x));
                ans=(long long int)(ans-(result(n-v[i])+result(v[i]-v[i-1]-1)));
                continue;
            }
            if(i==0)
            {
                long long int x=v[i+1]-1;
                ans=(long long int )(ans+result(x));
                ans=(long long int)(ans-(result(v[i+1]-v[i]-1)+result(v[i]-1)));
                continue;
            }
            ans=(long long int)(ans+result(v[i+1]-v[i-1]-1));
            ans=(long long int)(ans-(result(v[i+1]-v[i]-1)+result(v[i]-v[i-1]-1)));     
        }
        long long int res= (long long int)(result(n)-ans);
        cout<<res<<endl;
    }
    return 0;
}

