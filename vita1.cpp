#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char c[n + 1][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }
    int a[n + 1];
    int b[n + 1];
    int e[n + 1], f[n + 1];
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
        b[i] = 0;
        e[i] = 0;
        f[i] = 0;
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (c[i][j] == 'C')
                a[j]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (c[i][j] == 'C')
                b[i]++;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (c[i][j] == 'C')
                e[i]++;
        }
    }
    for (int j = n - 1; j >= 0; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (c[i][j] == 'C')
                f[j]++;
        }
    }
    int x1 = a[0];
    int y1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            y1++;
        else
        {
            break;
        }
    }
    int res1 = min(x1, y1);
    int x2 = b[0];
    int y2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] > 0)
            y2++;
        else
        {
            break;
        }
    }
    int res2 = min(x2, y2);
    int x3 = e[n - 1];
    int y3 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        //cout << e[i] << " ";
        if (e[i] > 0)
            y3++;
        else
        {
            break;
        }
    }
    int res3 = min(x3, y3);
    int x4 = f[n - 1];
    int y4 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (f[i] > 0)
            y4++;
        else
        {
            break;
        }
    }
    int res4 = min(x4, y4);
    int ans = max(max(res1, res2), max(res3, res4));
    cout << ans;
    return 0;
}