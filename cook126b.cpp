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
    int n, m;
    cin >> n >> m;
    char s[n + 1][m + 1];
    char s1[n + 1][m + 1], s2[n + 1][m + 1];
    int count1 = 0;
    int count2 = 0;
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == '.')
                c1++;
            else
                c2++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2 == 0)
            {
                s1[i][j] = '*';
                s2[i][j] = '.';
            }
            else
            {
                s1[i][j] = '.';
                s2[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] != s1[i][j])
            {
                count1++;
            }
            if (s[i][j] != s2[i][j])
            {
                count2++;
            }
        }
    }
    if (n % 2 == 1 && m % 2 == 1)
    {
        cout << count1 << "\n";
    }
    else
    {
        int ans = min(count1, count2);
        cout << ans << "\n";
    }
    //cout << min(count1, count2) << endl;
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