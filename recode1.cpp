#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        /*int x=s.length(),y;
        if(x%2==0)
        {
            y=x;
        }
        else
        {
            y=x+1;
        }
        
        for(int i=0;i<x/2;i++)
        {
            if((s[0]!=s[x/2+i]) || s.length()<=2)
            {

            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        int flag=1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==s[i+1])
            {
                continue;
            }
            else
            {
                flag=0;
            }
        }
        if(flag==0 || s.length()<=2)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }*/
        string s1=s;
        rotate(s1.begin(),s1.begin()+1,s1.end());
        string s2=s;
        rotate(s2.begin(),s2.begin()+s2.size()-1,s2.end());
        if(s1==s2)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}