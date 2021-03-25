#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int n = a.length();
        int len = 0;
        int count = 0;
        int count1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
                continue;
            int l = i;
            while (l < n && (a[l] != b[l]))
            {
                a[l] = b[l];
                l = l + 2;
            }
            count++;
        }
        cout << count << endl;
    }
    return 0;
}