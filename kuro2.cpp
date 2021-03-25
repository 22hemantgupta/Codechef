#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    string s1,s2;
    int count1=0,count2=0,k=1;
    if(n%2!=0)
    {
        for(int i=0;i<n/2;i++)
        {
            if(s[i]=='(')
            {
                count1++;
            }
        }
        for(int i=((n/2)+1);i<n;i++)
        {
            if(s[i]==')')
            {
                count2++;
            }
        }
        int m=0,n=0;
        if(count1>count2 && s[n/2]==')')
        {
            cout<<k;
            cout<<endl;
            cout<<count2+1;
            cout<<endl;
            for(int i=0;i<n/2;i++)
            {
                if(s[i]=='(')
                {
                    m++;
                    cout<<i+1<<" ";
                }
                if(m == count2)
                break;
            }
            cout<<n/2+1<<" ";
            for(int i=((n/2)+1);i<n;i++)
            {
                if(s[i]==')')
                {
                    cout<<i+1<<" ";
                    n++;
                }
                if(n == count2)
                break;
            }
        }
        else if(count1<count2 && s[n/2]=='(')
        {
            cout<<k;
            cout<<endl;
            cout<<count1+1;
            cout<<endl;
            for(int i=0;i<n/2;i++)
            {
                if(s[i]=='(')
                {
                    m++;
                    cout<<i+1<<" ";
                }
                if(m == count1)
                break;
            }
            cout<<n/2+1<<" ";
            for(int i=((n/2)+1);i<n;i++)
            {
                if(s[i]==')')
                {
                    n++;
                    cout<<i+1<<" ";
                }
                if(n == count1)
                break;
            }
        }
        else
        {
            cout<<k;
            cout<<endl;
            cout<<count2;
            cout<<endl;
            for(int i=0;i<n/2;i++)
            {
                if(s[i]=='(')
                {
                    m++;
                    cout<<i+1<<" ";
                }
                if(m == count2)
                break;
            }
            for(int i=((n/2)+1);i<n;i++)
            {
                if(s[i]==')')
                {
                    n++;
                    cout<<i+1<<" ";
                }
                if(n == count2)
                break;
            }
        }
    }
    else
    {
        for(int i=0;i<n/2;i++)
        {
            if(s[i]=='(')
            {
                count1++;
            }
        }
        for(int i=((n/2)+1);i<n;i++)
        {
            if(s[i]==')')
            {
                count2++;
            }
        }
        int m=0,n=0;
        if(count1>count2)
        {
            cout<<k;
            cout<<endl;
            cout<<count2;
            cout<<endl;
            for(int i=0;i<n/2;i++)
            {
                if(s[i]=='(')
                {
                    m++;
                    cout<<i+1<<" ";
                }
                if(m == count2)
                break;
            }
            for(int i=(n/2);i<n;i++)
            {
                if(s[i]==')')
                {
                    n++;
                    cout<<i+1<<" ";
                }
                if(n == count2)
                break;
            }
        }
        else
        {
            cout<<k;
            cout<<endl;
            cout<<count1;
            cout<<endl;
            for(int i=0;i<n/2;i++)
            {
                if(s[i]=='(')
                {
                    m++;
                    cout<<i+1<<" ";
                }
                if(m == count1)
                break;
            }
            for(int i=(n/2);i<n;i++)
            {
                if(s[i]==')')
                {
                    n++;
                    cout<<i+1<<" ";
                }
                if(n == count1)
                break;
            }
        }
    }
    return 0;
}