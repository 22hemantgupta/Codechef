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
        long long int res=0;
        if(n%2==0)
        {
            res=(n/2)*((2*n)-2);
            if(res==0)
            res=1;
        }
        else
        {
            res=((n/2)+1)*((2*n)-2);
            if(res==0)
            res=1;
        }
        cout<<res<<endl;
    }
    return 0;
}