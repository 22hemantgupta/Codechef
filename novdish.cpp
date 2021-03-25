#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int c[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        sort(c, c + n);
        if (n == 1)
        {
            cout << c[0] << endl;
        }
        else if (n == 2)
        {
            cout << max(c[0], c[1]) << endl;
        }
        else if (n == 3)
        {
            int ans1 = max((c[0] + c[1]), c[2]);
            int ans2 = max(c[0] + c[2], c[1]);
            cout << min(ans1, ans2) << endl;
        }
        else
        {
            int ans1 = max(c[0] + c[3], c[1] + c[2]);
            int ans2 = max(c[0] + c[1], c[2] + c[3]);
            int ans3 = max(c[0] + c[1] + c[2], c[3]);
            int ans = min(min(ans1, ans2), ans3);
            cout << ans << endl;
        }
    }
    return 0;
}