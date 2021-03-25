#include <bits/stdc++.h>
#define ll long long int
#define MOD 998244353
using namespace std;
ll add(ll x, ll y)
{
    ll res = x + y;
    return (res >= MOD ? res - MOD : res);
}
ll mul(ll x, ll y)
{
    ll res = x * y;
    return (res >= MOD ? res % MOD : res);
}
ll sub(ll x, ll y)
{
    ll res = x - y;
    return (res < 0 ? res + MOD : res);
}
ll power(ll x, ll y)
{
    ll res = 1;
    x % MOD;
    while (y)
    {
        if (y & 1)
            res = mul(res, x);
        y >>= 1;
        x = mul(x, x);
    }
    return res;
}
ll mod_inv(ll x) { return power(x, MOD - 2); }
int main()
{
    return 0;
}