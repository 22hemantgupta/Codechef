#include<iostream>
using namespace std;
int main()
{
    int T;
    int i=1;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int count =0;
        for(int i=0;i<n;i++)
        {
            if((i!=0 && i!=n))
            {
                if(a[i-1]<a[i] && a[i]>a[i+1])
                {
                    count++;
                }
            }
        }
        cout<<"Case #"<<i<<": "<<count<<endl;
        i++;
    }
    return 0;
}
