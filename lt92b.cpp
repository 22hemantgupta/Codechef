/* Hemant Gupta */
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define show(v)                             \
    for (int i = 0; i < (int)v.size(); i++) \
        cout << v[i] << (i == (int)v.size() - 1 ? "\n" : " ");
#define pb push_back
#define INF 1e18 + 5
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
vector<int> adj[N];
vector<bool> vis(N), take(N);
int lis(vector<int> &v, int n)
{
    int lis[n];

    lis[0] = 1;

    /* Compute optimized LIS values in  
       bottom up manner */
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (v[i] >= v[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}
int CeilIndex(std::vector<int> &v, int l, int r, int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (v[m] > key)
            r = m;
        else
            l = m;
    }

    return r;
}

int LongestIncreasingSubsequenceLength(vector<int> &v)
{
    if (v.size() == 0)
        return 0;

    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++)
    {

        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];

        // v[i] extends largest subsequence
        else if (v[i] >= tail[length - 1])
            tail[length++] = v[i];

        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming grater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }

    return length;
}
void test_case()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    vector<int> v2;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            v.push_back(1);
            c1++;
        }
        else
        {
            v.push_back(0);
            c2++;
        }
    }
    int ans1 = 0;
    //cout << v1.size();
    /*for (int i = 1; i < v1.size(); i++)
    {
        //cout << v1[i];
        ans1 = ans1 + (v1[i] - v1[i - 1] - 1);
        //cout << ans1 << " ";
        if (i == v1.size() - 1)
        {
            ans1 = ans1 + (n - v1[i] - 1);
        }
    }
    int ans2 = 0;
    for (int i = 1; i < v2.size(); i++)
    {
        ans2 = ans2 + (v2[i] - v2[i - 1] - 1);
        if (i == 1)
        {
            ans2 = ans2 + (v2[i] + 1 - 1);
        }
    }*/
    ans1 = n - LongestIncreasingSubsequenceLength(v);
    cout << ans1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--)
    {
        test_case();
    }
    return 0;
}