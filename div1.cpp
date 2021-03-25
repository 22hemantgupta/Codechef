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
        string s[n + 1];
        int count[26];
        for (int i = 0; i < 26; i++)
        {
            count[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            for (int j = 0; j < s[i].length(); j++)
            {
                count[s[i][j] - 'a']++;
            }
        }
        bool flag = true;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] % n != 0 && count[i] != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}