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
        long int days=0;
        long long int count=0,count1=0;
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
            {
                if(x>=a[i])
                {
                    days++;
                }
                else
                {
                    while(x<a[i])
                    {
                        days++;
                        x=x*2;
                       // a[i]=min(2*(a[i]-x),a[i]);
                    }
                    days++;
                }
            }
            else if(x>a[i] && (i+1<n && x>a[i+1]))
            {
                days++;
                //cout<<1<<" ";
            }
            else if(x>a[i] && (i+1<n && x<a[i+1]))
            {
                count++;
                while(x<a[i+1])
                {
                    x=x*2;
                    days++;
                   // a[i+1]=min(2*(a[i+1]-x),a[i+1]);
                }
                days++;
                x=a[i+1]*2;
                i++;
            }
            else if(x>a[i] && (i+1<n && x==a[i+1]))
            {
                days++;
                x=a[i+1]*2;
            }
            else if(x==a[i])
            {
                /*while(x<a[i])
                {
                    x=x*2;
                    days++;
                    a[i]=min(2*(a[i]-x),a[i]);
                }*/
                days++;
                x=a[i]*2;
            }
            else if(x<a[i] && (i+1<n && x<a[i+1]))
            {
                days++;
            }
            
        }
        cout<<(days+count+count1)<<endl;
    }
}