#include <bits/stdc++.h>
using namespace std;
bool sortcol(const vector<int> &v1,
             const vector<int> &v2)
{
    return v1[0] < v2[0];
}
int main()
{
    int t;
    cin >> t;
    int u = 1;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i][0];
            cin >> a[i][1];
        }
        sort(a.begin(), a.end(), sortcol);
        int r = 1;
        int c1 = 0;
        if ((a[0][1] - a[0][0]) % k == 0)
        {
            c1 = (a[0][1] - a[0][0]) / k;
        }
        else
        {
            c1 = ((a[0][1] - a[0][0]) / k) + 1;
        }
        r = a[0][0] + c1 * k;
        cout << c1 << " h";
        int count = c1;
        for (int i = 1; i < a.size(); i++)
        {
            if (r >= a[i][1])
                continue;
            if (r > a[i][0])
            {
                int c2 = 0;
                if ((a[i][1] - a[i][0]) % k == 0)
                {
                    c2 = (a[i][1] - a[i][0]) / k;
                }
                else
                {
                    c2 = ((a[i][1] - a[i][0]) / k) + 1;
                }
                count = count + c2;
                r = r + c2 * k;
            }
            else
            {
                int c2 = 0;
                if ((a[i][1] - a[i][0]) % k == 0)
                {
                    c2 = (a[i][1] - a[i][0]) / k;
                }
                else
                {
                    c2 = ((a[i][1] - a[i][0]) / k) + 1;
                }
                count = count + c2;
                //r=r+c2*k;
                r = a[i][0] + c2 * k;
            }
            cout << count << " ";
        }
        cout << "Case #" << u << ": " << count;
        cout << endl;
        u++;
    }
    return 0;
}