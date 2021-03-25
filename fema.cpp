#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> m;
        vector<int> f;
        int a[n];
        vector<int> x;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (s[i] == ':')
                    a[i] = 1;
                else
                {
                    a[i] = 0;
                }
            }
            else
            {
                a[i] = a[i - 1];
                if (s[i] == ':')
                    a[i]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'I')
                f.push_back(i);
            if (s[i] == 'M')
                m.push_back(i);
            if (s[i] == 'X')
                x.push_back(i);
        }
        int count = 0;
        for (int i = 0; i < m.size(); i++)
        {
            cout << f.size() << " ";
            for (int j = 0; j < f.size(); j++)
            {
                if (f[j] < m[i])
                {
                    int temp = k + 1 - abs(m[i] - f[j]);
                    int l = 0;
                    int r = x.size() - 1;
                    bool flag = false;
                    while (l <= r)
                    {
                        int mid = (l + r) / 2;
                        if (x[mid] > f[j] && x[mid] < m[i])
                        {
                            flag = true;
                            break;
                        }
                        if (x[mid] > f[j] && x[mid] > m[i])
                        {
                            r = mid - 1;
                        }
                        if (x[mid] < f[j] && x[mid] < m[i])
                        {
                            l = mid + 1;
                        }
                    }
                    temp = temp - (abs(a[i] - a[j]));
                    if (temp > 0 && flag == false)
                    {
                        count++;
                        f.erase(f.begin() + j);
                        break;
                    }
                }
                else
                {
                    int temp = k + 1 - abs(m[i] - f[j]);
                    int l = 0;
                    int r = x.size() - 1;
                    bool flag = false;
                    while (l <= r)
                    {
                        int mid = (l + r) / 2;
                        if (x[mid] < f[j] && x[mid] > m[i])
                        {
                            flag = true;
                            break;
                        }
                        if (x[mid] > f[j] && x[mid] > m[i])
                        {
                            r = mid - 1;
                        }
                        if (x[mid] < f[j] && x[mid] < m[i])
                        {
                            l = mid + 1;
                        }
                    }
                    temp = temp - (abs(a[m[i]] - a[f[j]]));
                    if (temp > 0 && flag == false)
                    {
                        count++;
                        f.erase(f.begin() + j);
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}