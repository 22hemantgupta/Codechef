#include <bits/stdc++.h>
using namespace std;
long long int binomialCoeff(long long int n, long long int k)
{
    long long int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, C, k;
        cin >> n >> C >> k;
        long long int c[n + 1];
        long long int a[n + 1], b[n + 1];
        long long int f[C + 1];
        for (int i = 1; i <= C; i++)
        {
            f[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            //long long int a, b;
            cin >> a[i] >> b[i] >> c[i];
            //if (a[i] != 0 || b[i] != 0)
            f[c[i]]++;
        }
        long long int v[C + 1];
        for (int i = 1; i <= C; i++)
        {
            cin >> v[i];
        }
        long long int count = 0;
        while (k >= v[1])
        {
            k = k - v[1];
            count++;
        }
        //cout << count << " cc\n";
        while (count > 0)
        {
            //sort(f + 1, f + (C + 1), greater<long long int>());
            //f[1] = f[1] - 1;
            int ma = f[1];
            int in = 1;
            for (int i = 2; i <= C; i++)
            {
                if (f[i] > ma)
                {
                    ma = f[i];
                    in = i;
                }
            }
            f[in] = f[in] - 1;
            count--;
        }
        /*for (long long int i = 1; i <= C; i++)
        {
            cout << f[i] << " f ";
        }*/
        //cout << f[1] << endl;
        long long int res = 0;
        //sort(f + 1, f + (C + 1), greater<long long int>());
        for (int i = 1; i <= C; i++)
        {
            if (f[i] >= 3)
            {
                res = res + binomialCoeff(f[i], 3);
            }
        }
        cout << res << endl;
    }
    return 0;
}