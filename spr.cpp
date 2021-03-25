#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
void update(long FenwickTree[], long n, long index, long val)
{
    while (index <= n)
    {
        FenwickTree[index] += val;
        index += (index & -index);
    }
}

long getSum(long FenwickTree[], long index)
{
    long sum = 0;
    while (index > 0)
    {
        sum += FenwickTree[index];
        index -= (index & -index);
    }
    return sum;
}

void updateRange(long FenwickTree[], long n, long l, long r, long val)
{
    update(FenwickTree, n, l, val);
    update(FenwickTree, n, r + 1, -val);
}
int main()
{

    long t, n, i, l, r, val, k, q;
    t = 1;
    while (t--)
    {
        cin >> n >> q >> k;
        long FenwickTree[n + 1];
        for (i = 0; i <= n; i++)
            FenwickTree[i] = 0;

        char s;

        while (q--)
        {
            cin >> s;
            if (s == 'Q')
            {
                cin >> l;

                cout << getSum(FenwickTree, l) + k << endl;
            }
            else if (s == 'S')
            {
                cin >> l >> r >> val;
                updateRange(FenwickTree, n, l, r, val);
            }
        }
    }
    return 0;
}