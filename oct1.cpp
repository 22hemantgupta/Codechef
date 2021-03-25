#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, p, k;
        cin >> n >> x >> p >> k;
        int a[n + 1];
        p = p - 1;
        k = k - 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int ans = 0;
        if (n == 1)
        {
            if (a[p] == x)
                ans = 0;
            else
            {
                ans = 1;
            }
        }
        else
        {
            if (k > p)
            {
                if (a[p] < x)
                {
                    ans = -1;
                }
                else if (a[p] == x)
                {
                    ans = 0;
                }
                else
                {
                    int i = p;
                    int count = 0;
                    while (i >= 0 && a[i] > x)
                    {
                        count++;
                        i--;
                    }
                    ans = count;
                }
            }
            else if (k == p)
            {
                int ans1 = 0, ans2 = 0;
                if (a[k] > x)
                {
                    if (a[p] < x)
                    {
                        ans = -1;
                    }
                    else if (a[p] == x)
                    {
                        ans = 0;
                    }
                    else
                    {
                        int i = p;
                        int count = 0;
                        while (i >= 0 && a[i] > x)
                        {
                            count++;
                            i--;
                        }
                        ans = count;
                    }
                }
                else
                {
                    if (a[p] > x)
                    {
                        ans = -1;
                    }
                    else if (a[p] == x)
                    {
                        ans = 0;
                    }
                    else
                    {
                        int i = p;
                        int count = 0;
                        while (i < n && a[i] < x)
                        {
                            count++;
                            i++;
                        }
                        ans = count;
                    }
                }
                /*if (ans1 != -1 && ans2 != -1)
                {
                    ans = min(ans1, ans2);
                }
                else if (ans1 == -1)
                {
                    ans = ans2;
                }
                else if (ans == -1)
                {
                    ans = ans1;
                }*/
            }
            else
            {
                if (a[p] > x)
                {
                    ans = -1;
                }
                else if (a[p] == x)
                {
                    ans = 0;
                }
                else
                {
                    int i = p;
                    int count = 0;
                    while (i < n && a[i] < x)
                    {
                        count++;
                        i++;
                    }
                    ans = count;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}