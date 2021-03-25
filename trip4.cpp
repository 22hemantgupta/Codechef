#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n+1];
        bool v[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        vector<pair<int, int> > doub;
        vector<tuple<int, int, int> > ans;
        for(int i=1;i<=n;i++)
        {
            v[i]=false;
        }
        for(int i=1;i<=n;i++)
        {
            if(!v[i])
            {
                 vector<int> cyc;
                int j=i;
                while(!v[j])
                {
                    v[j]=true;
                    cyc.push_back(j);
                    j=a[j];
                }
            while(cyc.size()>2)
            {
                int z=cyc.back();
                cyc.pop_back();
                int y=cyc.back();
                cyc.pop_back();
                int x=cyc.back();
                if(cyc.size()==1)
                {
                    cyc.pop_back();
                }
                ans.push_back(tie(x,y,z));
                --k;
            }
            if(cyc.size()==2)
            {
                doub.push_back(make_pair(cyc[0],cyc[1]));
            }
        }
        }
        while(doub.size()>1)
        {
            pair<int,int> one = doub.back();
            doub.pop_back();
            pair<int,int> two = doub.back();
            doub.pop_back();
            ans.push_back(tie(one.second,two.first,two.second));
            ans.push_back(tie(one.first,one.second,two.first));
            k=k-2;
        }
        if(!doub.empty())
        {
            k=-1;
        }
        if(k<0)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<ans.size()<<endl;
            for(int i=0;i<ans.size();i++)
            {
                cout<<get<0>(ans[i])<<" "<<get<1>(ans[i])<<" "<<get<2>(ans[i])<<endl;       
            }
        }
       /* else
        {
            cout<<"-1"<<endl;
        }*/
        
    }
    return 0;
}