#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        int count=0;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='x' && s[i-1]=='y')
            {
                i++;
                count++;
            }
            else if(s[i]=='y' && s[i-1]=='x')
            {
                i++;
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}