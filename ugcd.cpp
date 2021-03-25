#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<1<<"\n";
            cout<<1<<" "<<1<<"\n";
        }
        else if(n==2)
        {
            cout<<1<<"\n";
            cout<<1<<" "<<1<<" "<<2<<"\n";
        }
        else if(n==3)
        {
            cout<<1<<"\n";
            cout<<1<<" "<<1<<" "<<2<<" "<<3<<"\n";
        }
        else if(n%2==0)
        {
            cout<<n/2<<"\n";
            int x=2;
            int a=1;
            int b=2;
            for(int i=0;i<n/2;i++)
            {
                cout<<x<<" "<<a<<" "<<b<<"\n";
                a=a+2;
                b=b+2;
            }
        }
        else
        {
            cout<<n/2<<"\n";
            int a=1;
            int b=2;
            cout<<3<<" "<<a<<" "<<b<<" "<<n<<"\n";
            a=a+2;
            b=b+2;
            int x=2;
            for(int i=1;i<n/2;i++)
            {
                cout<<x<<" "<<a<<" "<<b<<"\n";
                a=a+2;
                b=b+2;
            }
        }
        
    }
    return 0;
}