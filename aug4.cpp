#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string p, s;
        cin>>s>>p;
        if (s.length()==p.length())
        {
            cout<<s<<endl;
            continue;
        }
        string res="";
        int f1[26];
        int f2[26];
        for (int i=0;i<26;i++)
        {
            f1[i]=0;
            f2[i]=0;
        }
        for (int i=0;i<s.length();i++)
        {
            f1[s[i]-'a']++;
        }
        for (int i=0;i<p.length();i++)
        {
            f2[p[i]-'a']++;
        }
        /* for (int i=0;i<26;i++)
         {
             cout<<" "<<f1[i];
         }*/
         //cout<<endl;
        int x=p[0]-'a';
        //cout<<p[0]-'a';
        //cout<<x<<endl;
        for (int i=0;i<x;i++)
        {
            if (f1[i]!=0)
            {
                int y=f1[i]-f2[i];
                f1[i]=f2[i];
                for (int j=0;j<y;j++)
                {
                    res=res+(char)(i+97);
                }
            }
        }
        /*for (int i=0;i<26;i++)
        {
            cout<<" "<<f1[i];
        }*/
        //cout<<res<<endl;
        if (f1[x]==f2[x])
            res=res+p;
        else
        {
            int l=1;
            for (int i=l;i<p.length();i++)
            {
                if ((p[i]-'a')==x)
                    l++;
                else
                {
                    break;
                }

            }
            for (int i=l;i<p.length();i++)
            {
                if ((p[i]-'a')<x)
                {
                    res=res+p;
                    int l=f1[x]-f2[x];
                    for (int j=0;j<l;j++)
                    {
                        res=res+char(x+97);
                    }
                    f1[x]=f2[x];
                    break;
                }
                else if ((p[i]-'a')>x)
                {
                    int l=f1[x]-f2[x];
                    for (int j=0;j<l;j++)
                    {
                        res=res+char(x+97);
                    }
                    res=res+p;
                    f1[x]=f2[x];
                    break;
                }
            }
        }

        //cout<<res<<endl;
        for (int i=0;i<26;i++)
        {
            if (f2[i]!=0)
                f1[i]=f1[i]-f2[i];
        }
        for (int i=x+1;i<26;i++)
        {
            if (f1[i]!=0)
            {
                for (int j=0;j<f1[i];j++)
                {
                    res=res+(char)(i+97);
                }
                f1[i]=0;
            }
        }
        res=res;
        //cout<<s.length()<<" "<<res.length();
        cout<<res<<endl;
    }
    return 0;
}