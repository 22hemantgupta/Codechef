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
    int n, k;
    cin >> n >> k;
    while (k % 2 == 0)
    {
        k /= 2;
    }
    int cnt = 0;
    for (int j = 1; j <= n; j++)
    {
        int c;
        cin >> c;
        if (c % k)
            cnt++;
    }

    if (cnt)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }

    return;
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