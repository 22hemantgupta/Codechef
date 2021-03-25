#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char org[100];
    int i, j, k = 0, len_org, len_dup;
   // cout<<"NOTE:Strings are accepted only till blank space.";
    //cout<<"\nEnter Original String:";
    fflush(stdin);
    cin>>org;
    //fflush(stdin);
    //cout<<"Enter Pattern to Search:";
    string dup="abacaba";
 
    len_org = strlen(org);
    len_dup = dup.length();
    for (i = 0; i <= (len_org - len_dup); i++)
    {
        for (j = 0; j < len_dup; j++)
        {
            //cout<<"comparing '"<<org[i + j]<<"' and '"<<dup[j]<<"'.";

            if(org[i+j]==dup[j] || (org[i+j]=='?' && k==0))
            continue;
            else
            {
                break;   
            }
        }
        if (j == len_dup)
        {
            k++;
            if(k==1)
            {
            for (j = 0; j < len_dup; j++)
            {
                if(org[i+j]=='?')
                org[i+j]=dup[j];
            }
            }
            //cout<<"\nPattern Found at Position: "<<i;
        }
    }
    for(i=0;i<(len_org);i++)
    {
        if(org[i]=='?')
        {
            org[i]='d';
        }
    }
    if (k == 1)
    {
        cout<<"YES"<<endl;
        for(i=0;i<len_org;i++)
        {
            cout<<org[i];
        }
        cout<<endl;
    }
    else
        cout<<"NO"<<endl;    
    }    
    return 0; 
} 