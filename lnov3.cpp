#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<int> dq;
        int index;
        long int ma = INT64_MIN;
        long long int f[n + 1], c[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> f[i];
            if (f[i] > ma)
            {
                ma = f[i];
                index = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        dq.push(index);
        long long int cost = f[index] * c[index];
        int j = (index + 1) % n;
        while (j != index)
        {
            if (!dq.empty() && c[dq.top()] >= c[j])
            {
                while (f[dq.top()] < f[j])
                {
                    cost = cost - (c[dq.top()] * f[dq.top()]) + (f[dq.top()] * c[j]);
                    dq.push(j);
                    f[dq.top()] = 0;
                    f[j] = f[j] - f[dq.top()];
                    if (!dq.empty() && f[dq.top()] <= 0)
                    {
                        dq.top();
                    }
                }
                if (f[dq.top()] >= f[j])
                {
                    cost = cost - (c[dq.top()] * f[j]) + (f[j] * c[j]);
                    dq.push(j);
                    f[dq.top()] -= f[j];
                    if (!dq.empty() && f[dq.top()] <= 0)
                    {
                        dq.pop();
                    }
                }
            }
            j = (j + 1) % n;
        }
        cout << cost << endl;
    }
    return 0;
}