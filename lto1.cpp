#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, q;
        cin >> n >> q;
        long long int a[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long int count = 1;
        long long int temp = 1;
        while (q--)
        {
            long long int x, y;
            cin >> x >> y;
            a[x - 1] = y;
            count = 1;
            temp = 1;
            for (int i = 1; i < n; i++)
            {
                //cout << temp << endl;
                if (a[i] != a[i - 1])
                {
                    temp++;
                    if (temp > count)
                        count = temp;
                }
                else //(a[i] == a[i - 1])
                {
                    temp = 1;
                }
            }
            if (temp > count)
                count = temp;
        }
        cout << count << endl;
        //cout << 0 << " " << n << endl;
    }
    return 0;
}