#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int l = 1, r = n;
    int p=1, q=n;
    bool flag=false;
    char def;
    //if(response1=='E')
      //  exit(0);
    int k=150;
    for(int i=0;i<k;i++)
    {
        int mid = (l + r ) / 2;
        char response;
        char response1;
        if( flag==false )
        {
        cout<<mid<<endl;
        fflush(stdout);
        cin>>response1;
        if(response1=='E')
            break;
        }
        else
        {
            response1=def;
        }
        mid=mid+1;
        cout<<mid<<endl;
        fflush(stdout);
        cin>>response;
        if(response=='E')
            break;
        if(response1==response)
        {
            if(response=='L')
            {
                r=mid-1;
            }
            else if(response=='G')
                l=mid+1;
            
            flag=false;
        } 
        else
        {
            def=response;
            flag=true;
            k++;
        }
    }
    return 0;   
}