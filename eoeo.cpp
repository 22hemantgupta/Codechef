#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int ts;
        cin>>ts;
        long long int res=0;
        if(ts%2!=0)
        {
            res=(ts-1)/2;
        }
        else
        {
            while(ts%2==0)
            {
                ts=ts/2;
            }
            res=(ts-1)/2;
        }
        cout<<res<<endl;
    }
    return 0;
}