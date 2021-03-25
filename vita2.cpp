#include <bits/stdc++.h>
using namespace std;
long long int maxPrimeFactors(long long int n)
{
    // Initialize the maximum prime factor
    // variable with the lowest one
    long long int maxPrime = -1;

    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        maxPrime = 2;
        n >>= 1; // equivalent to n /= 2
    }

    // n must be odd at this point, thus skip
    // the even numbers and iterate only for
    // odd integers
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            maxPrime = i;
            n = n / i;
        }
    }

    // This condition is to handle the case
    // when n is a prime number greater than 2
    if (n > 2)
        maxPrime = n;

    return maxPrime;
}
int main()
{
    long long int n1, n2;
    cin >> n1 >> n2;
    cout << maxPrimeFactors(n1);
    //cout << n1;
    vector<long long int> v1;
    vector<long long int> v2;
    v1.push_back(n1);
    v2.push_back(n2);
    //cout << n1;
    while (n1 > 1)
    {
        long long int x = maxPrimeFactors(n1);
        v1.push_back(x);
        n1 = x;
    }
    //cout << n2;
    while (n2 > 1)
    {
        long long int y = maxPrimeFactors(n2);
        v2.push_back(y);
        n2 = y;
    }
    vector<long long int> diff;
    //not need to sort since it already sorted
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(diff, diff.begin()));
    cout << diff.size();
    return 0;
}
