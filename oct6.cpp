#include <bits/stdc++.h>
using namespace std;
map<int, map<int, int>> mp;
int rec(long long int x1, long long int y1, long long int x2, long long int y2, int temp)
{
    long long int a = INT_MAX, b = INT_MAX, c = INT_MAX, d = INT_MAX, e = INT_MAX, f = INT_MAX;
    if (mp[x1].find(y1) != mp[x1].end())
    {
        return mp[x1][y1];
    }
    else
    {
        /*if ()
        {
            return mp[x1][y1] = INT_MAX;
        }*/
        if (temp >= 6 || x1 == 0 || y1 == 0)
        {
            //temp = 0;
            return mp[x1][y1] = INT_MAX;
        }
        if (((x1 != 0 && x2 != 0) && (y1 != 0 && y2 != 0)) && (x1 == x2 && y1 == y2))
        {
            //x = temp;
            return temp;
        }
        if (y1 > 0)
        {
            a = rec(x1 - (2 * y1), y1, x2, y2, temp + 1);
            //cout << x1 << " " << y1;
        }
        if ((y1 - (2 * x1)) < 0)
        {
            b = rec(-x1, -(y1 - (2 * x1)), x2, y2, temp + 1);
            //cout << x1 << " " << y1;
        }
        if ((y1 + (2 * x1)) < 0)
        {
            c = rec(-x1, -(y1 + (2 * x1)), x2, y2, temp + 1);
            //cout << x1 << " " << y1;
        }
        if (y1 > 0)
        {
            d = rec(x1 + (2 * y1), y1, x2, y2, temp + 1);
            //cout << x1 << " " << y1;
        }
        if ((y1 + (2 * x1)) > 0)
        {
            e = rec(x1, y1 + (x1 * 2), x2, y2, temp + 1);
            //cout << x1 << " " << y1;
        }
        if ((y1 - (2 * x1) > 0))
        {
            f = rec(x1, y1 - (2 * x1), x2, y2, temp + 1);
            //cout << x1 << " " << y1;
        }
        return mp[x1][y1] = min(min(min(min(min(a, b), c), d), e), f);
    }
    //}
    //return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        mp.clear();
        long long int temp = 0;
        long long int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        /*if (((x1 != 0 && x2 != 0) && (y1 != 0 && y2 != 0)) && (x1 == x2 && y1 == y2))
        {
            cout << 0 << endl;
            continue;
        }
        if ((x1 == -1 && y1 == 1) && (x2 == 1 && y2 == 1) || (x2 == -1 && y2 == 1) && (x1 == 1 && y1 == 1))
        {
            cout << 1 << endl;
            continue;
        }*/
        long long int z = rec(x1, y1, x2, y2, 0);
        cout << z << endl;
    }
    return 0;
}