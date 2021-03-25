#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, m;
    cin >> n >> m >> k;
    int a[n + 1][k + 1];
    long long int sum[n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            cin >> a[i][j];
            if (j != k)
            {
                sum[i] = sum[i] + a[i][j];
            }
        }
    }
    long int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum[i] >= m && a[i][k] <= 10)
            count++;
    }
    cout << count << endl;
    return 0;
}