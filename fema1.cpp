#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int count = 0;
        int a[n + 1];
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (s[i] == ':')
                    a[i] = 1;
                else
                {
                    a[i] = 0;
                }
            }
            else
            {
                a[i] = a[i - 1];
                if (s[i] == ':')
                    a[i]++;
            }
        }
        int ix = 0;
        int jx = 0;
        while (ix < n && jx < n)
        {
            if (s[ix] == 'M')
            {
                if (s[jx] == 'I')
                {
                    int temp = k + 1 - abs(ix - jx) - abs(a[ix] - a[jx]);
                    if (temp > 0)
                    {
                        count++;
                        ix++;
                        jx++;
                    }
                    else
                    {
                        if (ix > jx)
                            jx++;
                        else
                            ix++;
                    }
                }
                else if (s[jx] == 'X')
                {
                    ix = jx;
                    ix++;
                    jx++;
                }
                else
                {
                    jx++;
                }
            }
            else if (s[ix] == 'X')
            {
                jx = ix;
                ix++;
                jx++;
            }
            else
            {
                ix++;
            }
        }
        cout << count << endl;
    }
    return 0;
}