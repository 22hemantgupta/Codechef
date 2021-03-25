#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        char a[n+1][m+1];
        int p;
        if(2*x<=y)
        {
            y=2*x;
        }
        int price=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j+1<m)
                {
                    if(a[i][j]=='.' && a[i][j+1]=='.')
                    {
                        price=price +y;
                        j++;
                    }
                    else if(a[i][j]=='.')
                    {
                        price=price+x;
                    }
                }
                else
                {
                    if(a[i][j]=='.')
                    {
                        price = price+x;
                    }
                }
                
            }
        }
        cout<<price<<endl;
    }
}