#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int a[n + 1];
        long long int res[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        long long int m = 1;
        long long int mo = 1000000007;
        for (int i = n; i > 0; i--)
        {
            res[i] = m % mo;
            m = (m * 2) % mo;
            //cout<<res[i]<<" ";
        }
        for (int i = 1; i <= n; i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}