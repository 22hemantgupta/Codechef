#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;i++)
    {
        while (a[i]!=a[a[i]])
        {
            int temp=a[i];
            a[i]=a[a[i]];
            a[temp]=temp;
        }
    }
    //cout<<"hi";
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}