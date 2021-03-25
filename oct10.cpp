#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int temp = 0;
        long long int xx1, yy1, x2, y2;
        cin >> xx1 >> yy1 >> x2 >> y2;
        if (((xx1 != 0 && x2 != 0) && (yy1 != 0 && y2 != 0)) && (xx1 == x2 && yy1 == y2))
        {
            cout << 0 << endl;
            continue;
        }
        queue<pair<pair<long long int, long long int>, long long int>> q;
        int dist = 0;
        q.push({{xx1, yy1}, dist});
        map<long long int, map<long long int, long long int>> mp;
        long long int ans;
        while (!q.empty())
        {
            pair<pair<long long int, long long int>, long long int> p = q.front();
            long long int x1 = p.first.first;
            long long int y1 = p.first.second;
            if (x1 == x2 && y1 == y2)
            {
                break;
            }
            q.pop();
            if ((((x1 != 0 && x2 != 0) && (y1 != 0 && y2 != 0)) && mp[x1][y1] == 0) && (p.second < 100))
            {
                if (y1 > 0)
                {
                    q.push({{x1 - (2 * y1), y1}, p.second + 1});
                    //cout << x1 << " " << y1;
                }
                if ((y1 - (2 * x1)) < 0)
                {
                    q.push({{-x1, -(y1 - (2 * x1))}, p.second + 1});
                    //cout << x1 << " " << y1;
                }
                if ((y1 + (2 * x1)) < 0)
                {
                    q.push({{-x1, -(y1 + (2 * x1))}, p.second + 1});
                    //cout << x1 << " " << y1;
                }
                if (y1 > 0)
                {
                    q.push({{x1 + (2 * y1), y1}, p.second + 1});
                    //cout << x1 << " " << y1;
                }
                if ((y1 + (2 * x1)) > 0)
                {
                    q.push({{x1, y1 + (x1 * 2)}, p.second + 1});
                    //cout << x1 << " " << y1;
                }
                if ((y1 - (2 * x1) > 0))
                {
                    q.push({{x1, y1 - (2 * x1)}, p.second + 1});
                    //cout << x1 << " " << y1;
                }
                mp[x1][y1] = 1;
            }
        }
        cout << q.front().second << endl;
    }
    return 0;
}