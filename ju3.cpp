#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int k;
        cin>>k;
        char a[8][8];
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                a[i][j]='X';
            }
        }
        a[0][0]='O';
        int l=k/8;
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(!(i==0 && j==0))
                {
                    a[i][j]='.';
                }
            }
        }
        int m=k%8;
        for(int j=0;j<m;j++)
        {
            if(!(l==0 && j==0))
            {
                a[l][j]='.';
            }
        }
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}