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
        int a[n+1][n+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        int res[n+1][n+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                res[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                res[i][j]=res[i][j]+(a[i][j]*a[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}