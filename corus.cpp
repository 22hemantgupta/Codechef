#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,q;
        long long int c;
        cin>>n>>q;
        string s;
        cin>>s;
        long long int fre[26]={0};
        for(int i=0;i<n;i++)
        {
            fre[s[i]-'a']++;
        }
        /*for(int i=0;i<26;i++)
        {
            cout<<fre[i];
        }*/
        for(int i=0;i<q;i++)
        {
            long long int count=0;
            cin>>c;
            for(int j=0;j<26;j++)
            {
                if(fre[j]>c)
                {
                    count=count+(fre[j]-c);
                }
            }
            cout<<count<<endl;
        }
    }
    return 0;
}