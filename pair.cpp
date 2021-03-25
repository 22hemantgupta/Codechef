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
        int k=4*n-1;
        long int x[k+1],y[k+1];
        long int X,Y;
        for(int i=0;i<k;i++)
        {
            cin>>x[i]>>y[i];
        }
        bool flag=false;
        sort(x,x+k);
        sort(y,y+k);
        for(int i=0;i<k-1;i++)
        {
            if(x[i]!=x[i+1])
            {
                flag=true;
                X=x[i];
                break;
            }
            else
            {
                i++;
            }
        }
        if(flag==false)
        {
            X=x[k-1];
        }
        bool flag1=false;
        for(int i=0;i<k-1;i++)
        {
            if(y[i]!=y[i+1])
            {
                flag1=true;
                Y=y[i];
                break;
            }
            else
            {
                i++;
            }
        }
        if(flag1==false)
        {
            Y=y[k-1];
        }
        cout<<X<<" "<<Y<<endl;
    }
    return 0;
}