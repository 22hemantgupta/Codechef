#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int res=0;
    for(int i=30;i>=1;i--)
    {
        int maxsum=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]>i)
            {
                maxsum=0;
                continue;
            }
            maxsum=maxsum+a[j];
            maxsum=max(maxsum,int(0));
            res=max(res,maxsum-i);
        }
    }
    cout<<res<<"\n";
}