#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    //vector<Edge> edges;
    //Graph g(n);
    int h[n+1],a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(q--)
    {
        int f,b,c;
        cin>>f>>b>>c;
        if(f==1)
        {
            a[b]=c;
        }
        else if(f==2)
        {
            if(b!=c)
            {
                /*int* i1; 
                if(b>c)
                i1 = max_element(h+c,h+b);
                if(c>b)
                i1 = max_element(h+b,h+c);*/

                if((h[b]>h[c] && b>c))
                {
                    int x=h[b];
                    int y=h[c];
                    long int sum=a[b]+a[c];
                    for(int i=c+1;i<=b-1;i++)
                    {
                        if(h[i]>y && h[i]<x)
                        {
                            sum=sum+a[i];
                            y=h[i];
                        }
                        else if(h[i]>=x)
                        {
                            sum=-1;
                            break;
                        }
                        
                    }
                    cout<<sum<<endl;
                }
                else if((h[b]>h[c] && b<c))
                {
                    int x=h[b];
                    int y=h[c];
                    long int sum=a[b]+a[c];
                    for(int i=c-1;i>=b+1;i--)
                    {
                        if(h[i]>y && h[i]<x)
                        {
                            sum=sum+a[i];
                            y=h[i];
                        }
                        else if(h[i]>=x)
                        {
                            sum=-1;
                            break;
                        }
                    }
                    cout<<sum<<endl;
                }
                else
                {
                    cout<<-1<<endl;
                }
                
            }
            else
            {
                cout<<a[b]<<endl;
            }
        }
        
    }
    return 0;
}