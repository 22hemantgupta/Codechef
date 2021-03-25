#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a[n+1],b[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int j=0;j<n;j++)
        {
            cin>>b[j];
        }
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
        for(int j=0;j<n;j++)
        cout<<b[j]<<" ";
        cout<<endl;
    }
    return 0;
}