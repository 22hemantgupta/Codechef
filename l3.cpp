#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(long long int n)
{
    //finding the binary form of the number and
    //coneverting it to string.
    string s = bitset<64>(n).to_string();

    //Finding the first occurance of "1"
    //to strip off the leading zeroes.
    const auto loc1 = s.find('1');

    if (loc1 != string::npos)
        return s.substr(loc1);

    return "0";
}
long long int binaryToDecimal(string n)
{
    string num = n;
    long long int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    long long int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}
long long int bmax(long long int a, long long int b)
{
    string s1 = decimalToBinary(a);
    string s2 = decimalToBinary(b);
    string s3 = s1 + s2;
    string s4 = s2 + s1;
    long long int x = binaryToDecimal(s3);
    long long int y = binaryToDecimal(s4);
    return (x - y);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int a[n + 1];
        long long int max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long int y = bmax(a[i], a[j]);
                if (y > max)
                {
                    max = y;
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}