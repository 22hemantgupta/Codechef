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
int ans[1000001];
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    set<int> st;
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update al multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
            st.insert(p);
    }

    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 0;
    ans[3] = 0;
    for (int i = 4; i <= n; i++)
    {
        ans[i] = ans[i - 1];
        if (prime[i])
        {
            if (prime[i - 2])
            {
                ans[i]++;
            }
        }
    }
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SieveOfEratosthenes(1000000);
    int n;
    cin >> n;
    cout << ans[n] << endl;
    return 0;
}