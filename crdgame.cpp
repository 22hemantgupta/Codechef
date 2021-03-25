#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
/*long long int binomialCoeff(long long int n, long long int k)
{
    long long int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res = (res * (n - i));
        res /= (i + 1);
    }

    return res % mod;
}
long long int sum(long long int n, long long int k)
{
    long long int sum1 = 0;
    for (int i = 0; i <= k; i++)
    {
        sum1 = (sum1 + binomialCoeff(n, i)) % mod;
    }
    return sum1 % mod;
}
long long int binomialCoeffSum(int n)
{
    long int m = 1;
    for (int i = 0; i < n; i++)
    {
        m = (m * 2) % mod;
    }
    return m % mod;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int a[n + 1];
        int mac = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long int high = a[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == high)
                mac++;
            else
            {
                break;
            }
        }
        long int res = binomialCoeffSum(n - mac);
        long int ans = 0;
        if (n - mac == 0)
        {
            long int an = (mac + 1) / 2;
            long int te = binomialCoeffSum(an - 1);
            ans = (te * (binomialCoeff(mac, an - 1))) % mod;
            ans = (ans * 2) % mod;
        }
        else
        {
            long int an = (mac + 1) / 2;
            long long int answ = binomialCoeffSum(an - 1);
            long int ans1 = (res * answ) % mod;
            ans1 = (ans1 * binomialCoeff(mac, an - 1)) % mod;
            ans = (ans1 * 2) % mod;
        }
        cout << ans % mod << endl;
        //cout << binomialCoeff(5, 2);
    }
    return 0;
}*/
long long int powerLL(long long int x, long long int n)
{
    long long int res = 1;
    while (n)
    {
        if (n & 1)
            res = ((res % mod) * (x % mod)) % mod;
        n = n / 2;
        x = ((x % mod) * (x % mod)) % mod;
    }
    return res;
}
long long int div1(long long int a, long long int b)
{
    return (a % mod * (powerLL(b, mod - 2) % mod)) % mod;
}
long long int sol1(long long int n, long long int r)
{
    long long int ans = 1;
    long long int k = min(r, n - r);
    for (int i = 0; i < k; i++)
    {
        ans = ((ans % mod) * ((n - i) % mod)) % mod;
        ans = ans / (i + 1);
    }
    return ans % mod;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int a[n + 1], ans;
        int mac = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long int high = a[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == high)
                mac++;
            else
            {
                break;
            }
        }
        if (n == 1)
        {
            cout << 2 << endl;
            continue;
        }
        if (mac % 2 != 0)
            ans = powerLL(2, n) % mod;
        else
        {
            ans = powerLL(2, n) % mod - ((powerLL(2, n - mac) % mod) * sol1(mac, mac / 2) % mod) % mod;
        }
        if (ans < 0)
            ans = (ans + mod) % mod;
        ans = ans % mod;
        cout << ans << endl;
    }
    return 0;
}