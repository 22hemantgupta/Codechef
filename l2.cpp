#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, m, x, y;
        cin >> n >> m >> x >> y;
        long long int max = 0;
        long long int b = n * m;
        if (n == 1 && m == 1)
        {
            max = x;
        }
        else if (y / 2 >= x)
        {
            max = b * x;
        }
        else
        {
            int mx, nx;
            if (b % 2 == 0)
            {
                mx = b / 2;
                nx = b / 2;
            }
            else
            {
                mx = (b + 1) / 2;
                nx = b / 2;
            }
            if (y < x)
            {
                max = y * mx;
                cout << max << "\n";
                continue;
            }
            int p, q;
            p = x;
            q = y - x;
            if (p > q)
                max = mx * p + (nx * q);
            else
            {
                max = mx * q + (nx * p);
            }
        }
        cout << max << endl;
    }
    return 0;
}
