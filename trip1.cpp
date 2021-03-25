#include<bits/stdc++.h>
#include<map>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        int a[n+1];
        int b[n+1];
        int p[n+1];
        int r[k][3];
        int j=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            p[a[i]]=i;
        }
        int count=0;
        for(int i=1;i<n-1;i++)
        {
            if(a[i]!=i)
            {
                if(p[i]!=i+1)
                {
                int temp1=a[i];
                int l=p[i];
                p[a[i]]=i+1;
                a[i]=i;
                p[i]=i;
                int temp2=a[i+1];
                p[a[i+1]]=l;
                a[i+1]=temp1;
                a[l]=temp2;
                r[j][0]=l;
                r[j][1]=i;
                r[j][2]=i+1;
                j++;
                }
                else 
                {
                int temp1=a[i];
                int l=p[i];
                p[a[i]]=i+2;
                a[i]=i;
                p[i]=i;
                int temp2=a[i+2];
                p[a[i+2]]=l;
                a[i+2]=temp1;
                a[l]=temp2;
                r[j][0]=l;
                r[j][1]=i;
                r[j][2]=i+2;
                j++;
                } 
            }

        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=i)
            count++;
        }
        if(count==0)
        {
            cout<<j<<endl;
            for(int i=0;i<j;i++)
            {
                cout<<r[i][0]<<" "<<r[i][1]<<" "<<r[i][2]<<endl;
            }
        }
        else
        {
            int w=-1;
            cout<<w<<endl;
        }
    }
    return 0;
}
        