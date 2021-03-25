#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long int a[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int rootvalue = n - 1;
    long long int c = pow(a[n - 1], 1.0 / rootvalue);
    //cout << c;
    long long int res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++)
    {
        long long int x = pow(c, i);
        if (x > a[i])
        {
            res1 = res1 + (x - a[i]);
        }
        else if (x < a[i])
        {
            res1 = res1 + (a[i] - x);
        }
    }
    int c1 = c + 1;
    for (int i = 0; i < n; i++)
    {
        long long int x = pow(c1, i);
        if (x > a[i])
        {
            res2 = res2 + (x - a[i]);
        }
        else
        {
            res2 = res2 + (a[i] - x);
        }
    }
    long long int res = min(res1, res2);
    cout << res;
    return 0;
}