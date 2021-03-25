#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        vector<int> v;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==1)
            {
                v.push_back(i);
            }
        }
        bool flag=true;
        for(int i=1;i<v.size();i++)
        {
            int x = v[i-1];
            int y=v[i];
            if((y-x)<6)
            {
                flag=false;
                break;
            }
        }
        if(flag == false)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}