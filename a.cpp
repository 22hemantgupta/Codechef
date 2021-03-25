/* Hemant Gupta */
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define show(v)                             \
    for (int i = 0; i < (int)v.size(); i++) \
        cout << v[i] << (i == (int)v.size() - 1 ? "\n" : " ");
#define pb push_back
#define INF 1e18 + 5
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
vector<int> adj[N];
vector<bool> vis(N), take(N);
void test_case()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int count=0;
    int min=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]!=min)
            count++;
    }
    cout<<count<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--)
    {
        test_case();
    }
    return 0;
}
