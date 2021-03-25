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
        int w=1;
        for(int i=1;i<=n;i++)
        {
            if(i%2!=0)
            {
                for(int j=1;j<=n;j++)
                {
                    cout<<w<<" ";
                    w++;
                }
                w--;
                w=w+n;
            }
            else
            {
                for(int j=1;j<=n;j++)
                {
                    cout<<w<<" ";
                    w--;
                }
                w++;
                w=w+n;
            }
            cout<<endl;
        }
    }
    return 0;
}