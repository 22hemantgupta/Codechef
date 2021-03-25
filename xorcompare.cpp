#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> x >> y >> n;
        if (x == y)
        {
            cout << 0 << endl;
        }
        else
        {
            int count = 0;
            n++;
            for (int j = 30; j >= 0; j--)
            {
                if ((x & (1 << j)) != (y & (1 << j)))
                {
                    for (int k = 29; k >= 0; k--)
                    {
                        if (j > k)
                        {
                            if (n & (1 << k))
                            {
                                if ((n & (1 << j)) == (x & (1 << j)))
                                {
                                    count += (1 << k);
                                }
                            }
                        }
                        else if (j == k)
                        {
                            if (n & (1 << k))
                            {
                                if ((x & (1 << j)) == 0)
                                {
                                    count += (1 << k);
                                }
                            }
                        }
                        else
                        {
                            if ((n & (1 << k)))
                            {
                                count += (1 << (k - 1));
                            }
                        }
                    }
                    break;
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}