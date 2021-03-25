#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long int n,k;
        cin>>n>>k;
        long int a[n+1],rem[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long int sum=0;
        for(int i=1;i<=n;i++)
        {
            rem[i]=a[i]%k;
            sum=sum+rem[i];
        }
        long int ans=0;
        ans=sum%k;
        cout<<ans<<endl;
    }
    return 0;
}