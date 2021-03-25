#include <bits/stdc++.h>
using namespace std;
//#define long long ll
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long int a[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        if (k == 1 || k == 0)
        {
            cout << 0 << endl;
            continue;
        }
        long long int ans = INT_MAX;
        for (int i = 0; i < n - k; i++)
        {
            long long int temp = a[k + i - 1] - a[i];
            if (temp < ans)
                ans = temp;
        }
        cout << ans << endl;
    }
    return 0;
}