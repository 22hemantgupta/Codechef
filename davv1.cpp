#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        long long int n;
        cin>>n;
        //long long int a[1000];
        long long int even=0, odd=0;
        //int i=1;
        while (n!=0)
        {
            int x;
            x=n%10;
            if (x%2==0)
                even=even+x;
            else
            {
                odd=odd+x;
            }
            n=n/10;
        }
        /*int k=i;
        for (int j=i-1;j>0;j=j-2)
        {
            odd=a[j]+odd;
        }
        for (int j=k-2;j>0;j=j-2)
        {
            even=even+a[j];
        }*/
        int ma=max((even+(2*odd)), (odd+(2*even)));
        cout<<ma<<endl;
    }
}