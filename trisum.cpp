#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1][n+1];
    int sum[n+1][n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cin>>a[i][j];
        }
    }
    sum[0][0]=a[0][0];
    for(int i=1;i<n;i++)
    {
        sum[i][0]=a[i][0]+sum[i-1][0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j<i)
            {
                sum[i][j]=max(sum[i-1][j-1],sum[i-1][j])+a[i][j];
            }
            else
            {
                sum[i][j]=a[i][j]+sum[i-1][j-1];
            }
        }
    }
    int res=sum[n-1][0];
    for(int i=1;i<n;i++)
    {
        if(res<sum[n-1][i])
        {
            res=sum[n-1][i];
        }
    }
    cout<<res<<endl;
    return 0;
}