#include<bits/stdc++.h>
using namespace std;
int getnum(vector<int>& v)
{
    int n = v.size();
    srand(time(NULL));
    int index= rand()%n;
    int num = v[index];
    swap(v[index] , v[n-1]);
    v.pop_back();
    return num;
}
void generator(int n)
{
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        v[i]=i+1;
    }
    while(v.size())
    {
        cout<<getnum(v)<<" ";
    }
}
int main()
{
    int t=1;
    cout<<t<<endl;
    int n=15;
    int k=15;
    cout<<n<<" "<<k<<endl;
    generator(n);
    return 0;
}