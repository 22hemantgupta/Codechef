#include <bits/stdc++.h>
using namespace std;
vector<int> pri;
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            pri.push_back(p);
}
int main()
{
    SieveOfEratosthenes(4000000);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int b[n + 1];
        int a[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            a[i] = pri[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (b[i] != i + 1)
            {
                a[i] = a[b[i] - 1];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}