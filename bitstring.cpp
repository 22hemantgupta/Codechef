#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool flag = true;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == '?')
        {
            for (int j = i + k; j < n; j += k)
            {
                if (s[j] != '?')
                {
                    s[i] = s[j];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (s[i] != '?')
        {
            for (int j = i + k; j < n; j += k)
            {
                if (s[j] == '?')
                {
                    s[j] = s[i];
                }
                else if (s[i] != s[j])
                {
                    //flag=false;
                    //break;
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (s[i] == '1')
            c1++;
        else if (s[i] == '0')
            c2++;
        else
            c3++;
    }

    if ((c1 > k / 2 || c2 > k / 2) || k % 2 != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}