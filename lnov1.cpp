#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int sum = a[0];
        int dist = 0;
        for (int i = 1; i < n; i++)
        {
            if (sum >= 1)
            {
                dist++;
                sum = sum + a[i] - 1;
            }
            else
            {
                break;
            }
        }
        cout << sum + dist << endl;
    }
    return 0;
}