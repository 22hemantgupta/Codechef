#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n, k;
        cin>>n>>k;
        int a[n+1];
        int minm=INT_MAX;
        int res=-1;
        bool flag= false;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
            if (k%a[i]==0 && k/a[i]<minm)
            {
                minm=k/a[i];
                //flag=true;
                res=a[i];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
