//#include <iostream>
#include <stdio.h>
int dp[10000];
int fun(int n)
{
    //if (dp[i]==-1)
    //{
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    return fun(n-1)+fun(n-2);
    //printf(" %d", dp[i]);
//}
}
int main()
{
    int n=10;
    for (int i=0;i<n;i++)
        dp[i]=fun(i);
    for (int i=0;i<n;i++)
        printf("  %d", dp[i]);
    return 0;
}