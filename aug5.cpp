#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        long int n, k;
        cin>>n>>k;
        long int a[n+1];
        long int c[101];
        long int f[101];
        long int arg=0;
        for (int i=1;i<=100;i++)
        {
            c[i]=0;
            f[i]=0;
        }
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }
        c[a[0]]=1;
        long int counter=1;
        for (int i=1;i<n;i++)
        {
            if (c[a[i]]>0)
            {
                counter++;
                for (int i=1;i<101;i++)
                    c[i]=0;
                c[a[i]]=1;
            }
            c[a[i]]=1;
        }
        for (int i=1;i<=100;i++)
        {
            c[i]=0;
            //f[i]=0;
        }
        for (int i=1;i<=100;i++)
        {
            if (f[i]>1)
                arg=arg+f[i];
        }
        //c[a[0]]=0;
        long int b[n+1];
        int c1=0;
        //int mi=INT_MAX;
        long int ar=0;
        //long int count=1;
        //int ans;
        for (int i=0;i<n;i++)
        {
            c[a[i]]++;
            if (c[a[i]]>1)
            {
                //count++;
                unordered_map<int, int>mp;
                ar=0;
                for (int j=0;j<i;j++)
                    mp[a[j]]++;
                for (int j=0;j<i;j++)
                {
                    if (mp[a[j]]>1 && mp[a[j]]!=-1)
                    {
                        ar=ar+mp[a[j]];
                        mp[a[j]]=-1;
                    }
                }
                mp.clear();
                for (int j=i;j<n;j++)
                    mp[a[j]]++;
                for (int j=i;j<n;j++)
                {
                    if (mp[a[j]]>1 && mp[a[j]]!=-1)
                    {
                        ar=ar+mp[a[j]];
                        mp[a[j]]=-1;
                    }
                }
                b[c1]=ar;
                c1++;
            }
            // c[a[i]]=1;
        }
        sort(b, b+c1);
        long int k1=k*counter;
        long int k2=k+arg;
        long int k3=(k*2)+b[0];
        cout<<min(min(k1, k2), k3)<<endl;
        //cout<<count<<endl;
    }
    return 0;
}