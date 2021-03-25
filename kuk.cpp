#include <bits/stdc++.h>
using namespace std;
// temp = 0;
int rec(int a[], int i, int skip, int n, int cost, int x)
{
    int temp = 0;
    if (i >= n - 1)
        return 0;
    if (skip == 0 || a[i] <= x)
    {
        temp += a[i] + rec(a, i + 1, 3, n, cost, x);
    }
    else
    {
        //temp = 0;
        temp = temp + min((x + rec(a, i + 1, skip - 1, n, cost, x)), a[i] + rec(a, i + 1, 3, n, cost, x));
    }
    return temp;
}
int main()
{
    int n, x;
    cin >> n >> x;
    int a[n + 1];
    long long int cost = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cost = a[0] + a[n - 1];
    int skip = 3;
    cost = cost + rec(a, 1, 3, n, cost, x);
    cout << cost;
    return 0;
}