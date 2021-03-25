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
        int a[n + 1];
        string s = "";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % k == 0)
                s = s + '1';
            else
                s = s + '0';
        }
        cout << s << endl;
    }
    return 0;
}
