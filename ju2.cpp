#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        int x=0,y=0;
        cin>>n;
        int a[n+1],b[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
            int c=a[i],m=b[i];
            int s1=0,s2=0;
            while(c!=0)
            {
                s1=s1+(c%10);
                c=c/10;
            }
            while(m!=0)
            {
                s2=s2+(m%10);
                m=m/10;
            }
            if(s1>s2)
            x++;
            else if(s2>s1)
            y++;
            else
            {
                x++;
                y++;
            }
        }
        if(x>y)
        {
            cout<<0<<" "<<x;
        }
        else if(y>x)
        {
            cout<<1<<" "<<y;
        }
        else
        {
            cout<<2<<" "<<x;
        }
        cout<<endl;
    }
}