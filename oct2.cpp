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
        int a[n + 1];
        int x = log2(n);
        int p = pow(2, x);
        if (p == n && n != 1)
        {
            int tem = -1;
            cout << tem << endl;
        }
        else
        {
            if (n == 1)
                cout << 1 << endl;
            else
            {
                a[1] = 2;
                a[2] = 3;
                a[3] = 1;
                int lo = x - 1;
                for (int i = 4; i <= n; i++)
                {
                    a[i] = i;
                }
                for (int i = 2; i <= x; i++)
                {
                    int u = pow(2, i);
                    int v = u + 1;
                    int temp = a[u];
                    a[u] = a[v];
                    a[v] = temp;
                }
                for (int i = 1; i <= n; i++)
                {
                    cout << a[i] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}