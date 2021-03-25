#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1];
    int pro=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int k=a[i]-a[j];
            pro=(pro*k)%m;
        }
    }
    if(pro<0)
    {
        pro=pro*(-1);
    }
    cout<<pro%m;
    return 0;
}