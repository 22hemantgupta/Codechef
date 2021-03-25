#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        long long int a[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long long int pro=1,k=0,l=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2!=0 || a[i]%4==0)
            k++;
            pro=a[i];
            for(int j=i+1;j<=n;j++)
            {
                pro = pro*a[j];
                if(pro%2!=0 || pro%4==0)
                l++;
            }
            pro=1;
        }
        cout<<k+l<<endl;
    }
    return 0;
}