#include<iostream>
using namespace std;

long int res[1002] = {0};


bool getAnsUtil(int index, long int p, long int a[], long int res[])
{
    if(index < 0)
        return false;
    if(p%a[index] != 0)
    {
        res[index] = p/a[index] + 1;
        return true;
    }
    else
    {
        res[index] = p/a[index] - 1;
        return getAnsUtil(index - 1, p - (p/a[index] - 1)*a[index], a, res);
    }
}

bool getAns(int index, long int p, long int a[], long int res[])
{
    for(int i = 0; i <  index; i++)
    {
        res[i] = 0;
    }
    return getAnsUtil(index, p, a, res); 
}


int main()
{
    long int t, n, a[1002], p;
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        for(int i=0;i <n; i++)
        {
            cin>>a[i];
        }
        bool flag = getAns(n-1, p, a, res);
        if(flag)
        {
            cout<<"YES"<<" ";
            for(int i=0;i <n; i++)
            {
                cout<< res[i] << " ";
            }
            cout<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}