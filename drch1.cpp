#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,x;
        cin>>n>>x;
        int a[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int y=a[0];
        int z=a[n-1];
        long int days=0;
        int count=0;
        bool flag=true;
        if(x>=z)
        {
            days=n;
        }
        else
        {
            for(int i=0;i<n;)
            {
                int temp;
                if(a[i]<=x)
                {
                    temp=x;
                    x=a[i]*2;
                    if(x<temp)
                    {
                        x=temp;
                    }
                    days++;
                    i++;
                }
                else 
                {
                    a[n-1]=min(2*(a[n-1]-x),a[n-1]);
                    x=x*2;
                    days++;
                }
            }
        }
        cout<<days<<endl;
    }
    return 0;
}