#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int h, p;
        cin>>h>>p;
        while (h>0 && p!=0)
        {
            h=h-p;
            if (h<=0)
            {
                cout<<1<<endl;
                break;
            }
            p=p/2;
            if (p==0)
            {
                cout<<0<<endl;
                break;
            }

        }
    }
    return 0;
}