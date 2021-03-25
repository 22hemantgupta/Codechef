#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = (int)j; i <= (int)k; i++)
#define per(i, j, k) for (int i = (int)j; i >= (int)k; i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N = 100005;
const int S = 450;
const int P = 1000000007;
inline void add(int &a, int b)
{
    a += b;
    if (a >= P)
        a -= P;
}
inline void dec(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += P;
}
inline int Pow(int a, int b)
{
    int c = 1;
    for (; b; b >>= 1, a = a * 1ll * a % P)
        if (b & 1)
            c = c * 1ll * a % P;
    return c;
}
int fac[N << 1], inv[N << 1];
int C(int a, int b)
{
    int ret = fac[a] * 1ll * inv[b] % P;
    return ret * 1ll * inv[a - b] % P;
}
int n, k;
int f[N], g[N];
int res[N];
void dp()
{
    f[0] = 1;
    rep(i, 0, S)
    {
        memset(g, 0, sizeof g);
        rep(j, 0, k) if (f[j])
        {
            if (i + j + 1 <= k)
                dec(g[i + j + 1], f[j]);
            if (i && (i + j <= k))
                add(f[j + i], f[j]);
        }
        rep(j, 0, k) add(res[j], f[j]), f[j] = g[j];
    }

    memset(f, 0, sizeof f);
    rep(i, 0, k) f[i] = res[i];
    memset(res, 0, sizeof res);
    rep(i, 0, k / n)
    {
        memset(g, 0, sizeof g);
        rep(j, 0, k) if (f[j])
        {
            if (i && (i + j <= k))
                add(f[i + j], f[j]);
            if (j + n + 1 <= k)
                add(g[j + n + 1], f[j]);
        }
        rep(j, 0, k) add(res[j], f[j]);
        rep(j, 0, k) f[j] = g[j];
    }
    int ans = 0;
    rep(j, 0, k)
    {
        int ret = res[j] * 1ll * C(k - j + n - 1, n - 1) % P;
        add(ans, ret);
    }
    cout << ans % 2 << endl;
}
int main()
{
    n = 200000;
    fac[0] = 1;
    rep(i, 1, n) fac[i] = fac[i - 1] * 1ll * i % P;
    inv[n] = Pow(fac[n], P - 2);
    per(i, n - 1, 0) inv[i] = inv[i + 1] * 1ll * (i + 1) % P;
    int t;
    cin >> t;
    t = t + 2;
    t = t - 2;
    while (t--)
    {
        cin >> n >> k;
        if (k == 0)
            cout << 1 << endl;
        else if (n == 0)
            cout << 0 << endl;
        else
            dp();
    }
    return 0;
}
