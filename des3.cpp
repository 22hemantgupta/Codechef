#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, d;
        cin >> n >> d;
        int a[n + 1];
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] >= 80 || a[i] <= 9)
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
        int ans = ceil((float)c1 / d) + ceil((float)c2 / d);
        cout << ans << endl;
    }
    return 0;
}