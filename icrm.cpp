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
        int a[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(a[0]!=5)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int sum=a[0];
        bool flag=true;
        int count1=1;
        int count2=0;
        for(int i=1;i<n;i++)
        {
            int dif=a[i]-5;
            if(dif==0)
            {
                count1++;
            }
            if(dif==5)
            {
                if(count1>0)
                {
                count1--;
                count2++;
                }
                else
                {
                    flag=false;
                    break;
                }
            }
            if(dif==10)
            {
                if(count2>0)
                {
                    count2--;
                }
                else if(count1>1)
                {
                    count1=count1-2;
                }
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag==true)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}