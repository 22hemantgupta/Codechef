
#include <iostream>
using namespace std;

void findSmallest(int m, int s)
{

    if (s == 0)
    {
        return;
    }

    // Sum greater than the maximum possible sum.
    if (s > 9 * m)
    {
        return;
    }

    // Create an array to store digits of result
    int res[m];

    s -= 2;

    // Fill last m-1 digits (from right to left)
    for (int i = m - 1; i > 0; i--)
    {
        // If sum is still greater than 9,
        // digit must be 9.
        if (s > 9)
        {
            res[i] = 9;
            s -= 9;
        }
        else if (s == 9)
        {
            res[i] = 8;
            s -= 8;
        }
        else
        {
            res[i] = s;
            s = 0;
        }
    }

    // Whatever is left should be the most significant
    // digit.
    res[0] = s + 2; // The initially subtracted 1 is
        // incorporated here.

    for (int i = 0; i < m; i++)
        cout << res[i];
}

// Driver code
int main()
{
    int m;
    int n;
    cin >> m >> n;
    findSmallest(m, n);
    return 0;
}
