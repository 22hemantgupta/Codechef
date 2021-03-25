#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long int s=0;
        int n;
        cin>>n;
        long int a[n+1],b[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0;i<n;i++)
        {
            s=min(a[i],b[i])+s;
        }
        cout<<s<<endl;
    }
}