#include <bits/stdc++.h>
using namespace std;
int main()
{
    int d1, v1, d2, v2, p;
    cin >> d1 >> v1 >> d2 >> v2 >> p;
    long int count = 0;
    int d = 1;
    while (p > count)
    {
        if (d >= d1)
        {
            count += v1;
        }
        if (d >= d2)
        {
            count += v2;
        }
        if (count < p)
            d++;
    }
    cout << d;
    return 0;
}
