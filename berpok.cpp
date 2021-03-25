#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k,max=0;
        cin>>n>>m>>k;
        int x=n/k;
        if(x>=m)
        {
            cout<<m<<endl;
        }
        else
        {
            int res;
            if((m-x)>(k-1))
            {
                if((m-x)%(k-1)==0)
                {
                    res=x-((m-x)/(k-1));
                }
            else
            {
            res=x-((m-x)/(k-1)+1);
            }
            }
            else
            {
                res=x-1;
            }
            cout<<res<<endl;
            /*else
            {
                int res=0;
                cout<<res<<endl;
            }*/
            
        }
    }
    return 0;
}