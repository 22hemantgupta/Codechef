#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b;
        cin >> a >> b;
        long long int x1, x2, y1, y2;
        if (a % 2 == 0)
        {
            x1 = a / 2;
            y1 = a / 2;
        }
        else if (a % 2 != 0)
        {
            x1 = a / 2;
            y1 = (a / 2) + 1;
        }
        if (b % 2 == 0)
        {
            x2 = b / 2;
            y2 = b / 2;
        }
        else if (b % 2 != 0)
        {
            x2 = b / 2;
            y2 = (b / 2) + 1;
        }
        long long int res = (x1 * x2) + (y1 * y2);
        cout << res << endl;
    }
    return 0;
}