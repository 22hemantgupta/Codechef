#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int c, r;
        cin>>c>>r;
        int x=c/9;
        if (c%9!=0)
            x=x+1;
        int y=r/9;
        if (r%9!=0)
            y=y+1;
        if (x<y)
        {
            cout<<0<<" "<<x<<endl;
        }
        else
        {
            cout<<1<<" "<<y<<endl;
        }
    }
    return 0;
}