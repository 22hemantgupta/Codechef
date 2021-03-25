#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char c[n + 1][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }
    int res = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (c[j][i] == 'D')
                res = res + 1;
        }
    }
    cout << floor(sqrt(res)) << endl;
    return 0;
}