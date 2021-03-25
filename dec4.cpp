#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 0; i < n; i++)
        {
            a[i] = i + 1;
        }
        int count = 0;
        if (n % 2 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] % 2 == 1)
                    a[i] = (-a[i]);
            }
            count = n / 2;
        }
        if (n % 2 != 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] % 2 == 0)
                    a[i] = (-a[i]);
            }
            count = (n / 2) + 1;
        }
        if (count > k)
        {
            int x = count - k;
            for (int i = n - 1; i >= 0; i--)
            {
                if (x > 0 && a[i] > 0)
                {
                    a[i] = (-a[i]);
                    x--;
                }
            }
        }
        if (count < k)
        {
            int x = k - count;
            for (int i = n - 1; i >= 0; i--)
            {
                if (x > 0 && a[i] < 0)
                {
                    a[i] = abs(a[i]);
                    x--;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}