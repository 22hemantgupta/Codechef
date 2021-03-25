

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000000;
const long long int MOD = 2;
long long int v1[MAXN], v2[MAXN];
int pentagonal(int x)
{
    return (x * (3 * x - 1)) / 2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        // compute stuff for comb
        v1[0] = 0;
        v2[0] = 0;
        for (int i = 1; i <= k; ++i)
        {
            v1[i] = v1[i - 1];
            v2[i] = v2[i - 1];
            if (((n - 1 + i)) % MOD == 0)
            {
                int count = 0;
                int dx = n - 1 + i;
                while (dx != 0 && dx % 2 == 0)
                {
                    dx = dx / 2;
                    count++;
                }
                v1[i] = v1[i - 1] + count;
            }
            if (i % 2 == 0)
            {
                int count = 0;
                int dx = i;
                while (dx != 0 && dx % 2 == 0)
                {
                    dx = dx / 2;
                    count++;
                }
                v2[i] = v2[i - 1] + count;
            }
        }
        //cout << v1[4] << " " << v2[4] << " ";
        //
        long long int ans = 0;
        for (int i = 1;; ++i)
        {
            long long int den = k - pentagonal(i) - i;
            if (den < 0)
                break;
            long long int temp = 0;
            // cout << den << " ";
            if (v1[den] > v2[den])
            {
                temp = 0;
            }
            else if (v1[den] == v2[den])
            {
                temp = 1;
            }
            ans = (ans + temp) % MOD;
        }
        for (int i = 1;; ++i)
        {
            long long int den = k - pentagonal(i);
            if (den < 0)
                break;

            // cout << den << " ";
            long long int temp = 0;
            if (v1[den] > v2[den])
            {
                temp = 0;
            }
            else if (v1[den] == v2[den])
            {
                temp = 1;
            }
            ans = (ans + temp) % MOD;
        }
        long long int res;
        if (v1[k] > v2[k])
        {
            res = 0;
        }
        else if (v1[k] == v2[k])
        {
            res = 1;
            //cout << "hi  ";
        }
        ans = (ans + res) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
