// C++ Program to find largest prime
// factor of number
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// A function to find largest prime factor
long long maxPrimeFactors(long long n)
{
    // Initialize the maximum prime factor
    // variable with the lowest one
    long long maxPrime = 1;

    // Print the number of 2s that divide n
    for (int i = 1; i <= (n); ++i)
    {
        if (n % i == 0)
        {
            maxPrime = i;
        }
        //cout << i << endl;
    }

    // This condition is to handle the case
    // when n is a prime number greater than 2
    //if (n > 2 && maxPrime == 1)
    //   maxPrime = 1;

    return maxPrime;
}

// Driver program to test above function
int main()
{
    long long n1, n2;
    //cout << maxPrimeFactors(n) << endl;

    //n = 25698751364526;
    //cout << maxPrimeFactors(19);
    cin >> n1;
    cin >> n2;
    vector<long long> v1;
    vector<long long> v2;
    v1.push_back(n1);
    v2.push_back(n2);
    //cout << n1;
    while (n1 > 1)
    {
        long long int x = maxPrimeFactors(n1);
        v1.push_back(x);
        n1 = x;
        cout << n1 << " ";
    }
    //cout << n2;
    while (n2 > 1)
    {
        long long int y = maxPrimeFactors(n2);
        v2.push_back(y);
        n2 = y;
        cout << n2 << " ";
    }
    vector<long long int> diff;
    //not need to sort since it already sorted
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(diff, diff.begin()));
    cout << diff.size();
    return 0;
    //while ()
}
// This code is contributed by Shivi_Aggarwal
