#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        vector<int> c;
        vector<int> d;
        char ch;
        cin>>ch;
        int a[3][3];
        int d[3][3];
        int m=1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                d[i][j]=m;
                m++;
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>a[i][j];
                if(a[i][j]==-1)
                {
                    c.push_back(d[i][j]);
                }
                else if(a[i][j]==1)
                {
                    d.push_back(d[i][j]);
                }
            }
        }
        if(ch=='x')
        {
            if(a[0][0]==1)
            {
                
                
            }
            
        }
    }
}