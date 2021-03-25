#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x;
        cin >> n >> x;
        long long a[n + 1];
        int bit = 30;
        vector<vector<long long>> fre(bit + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 2)
        {
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = bit; j >= 0; j--)
                {
                    long long mask = 1LL << j;
                    if (a[i] == 0 && x != 0)
                        break;
                    if ((a[i] & mask) == 0)
                    {
                        continue;
                    }
                    int d = n - 1;
                    a[i] = a[i] ^ mask;
                    d = n - 1;
                    a[d] = a[d] ^ mask;
                    x = x - 1;
                    if (x == 0)
                        break;
                }
                if (x == 0)
                    break;
                if (a[i] == 0 && x != 0)
                {
                    if (x % 2 == 1)
                    {
                        a[i] = 1;
                        a[n - 1] = a[n - 1] ^ 1;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
        }
        else
        {
            vector<long long> count(bit + 1, 0);
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = bit; j >= 0; j--)
                {
                    long long mask = 1LL << j;
                    if (a[i] & mask)
                    {
                        fre[j].push_back(i);
                    }
                }
            }
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = bit; j >= 0; j--)
                {
                    long long mask = 1LL << j;
                    if ((a[i] & mask) == 0)
                    {
                        continue;
                    }
                    a[i] = a[i] ^ mask;
                    long long int d;
                    if (++count[j] < fre[j].size())
                    {
                        d = fre[j][count[j]];
                        count[j]++;
                    }
                    else
                    {
                        d = n - 1;
                    }
                    a[d] = a[d] ^ mask;
                    x = x - 1;
                    if (x == 0)
                        break;
                }
                if (x == 0)
                    break;
            }
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}