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
    string s[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    vector<pair<string,int>> suf;
    for(int i=0;i<n;i++)
    {
        string su="";
        for(int x=1;x<s[i].size();x++)
        {
            su+=s[i][x];
        }
        suf.push_back({su,i});
    }

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