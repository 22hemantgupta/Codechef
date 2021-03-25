#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a[n+1],dif[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int max=INT_MIN;
        int min=INT_MAX;
        int count=1;
        for(int i=1;i<n;i++)
        {
            dif[i]=a[i]-a[i-1];
        }
        for(int i=1;i<n;i++)
        {
            if(dif[i]<=2)
            {
                count++;
            }
            else
            {
                if(count<min)
                min=count;
                if(count>max)
                max=count;
                count=1;
            }
        }
        if(count<min)
            min=count;
        if(count>max)
            max=count;
        cout<<min<<" "<<max<<endl;
    }
    return 0;
}