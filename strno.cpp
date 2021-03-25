#include<iostream>
#include<vector>
using namespace std;
void sieveOfEratosthenes(int N, int s[]) 
{ 
    // Create a boolean array "prime[0..n]" and 
    // initialize all entries in it as false. 
    vector <bool> prime(N+1, false); 
  
    // Initializing smallest factor equal to 2 
    // for all the even numbers 
    for (int i=2; i<=N; i+=2) 
        s[i] = 2; 
  
    // For odd numbers less then equal to n 
    for (int i=3; i<=N; i+=2) 
    { 
        if (prime[i] == false) 
        { 
            // s(i) for a prime is the number itself 
            s[i] = i; 
  
            // For all multiples of current prime number 
            for (int j=i; j*i<=N; j+=2) 
            { 
                if (prime[i*j] == false) 
                { 
                    prime[i*j] = true; 
  
                    // i is the smallest prime factor for 
                    // number "i*j". 
                    s[i*j] = i; 
                } 
            } 
        } 
    } 
} 
int generatePrimeFactors(int N) 
{ 
    // s[i] is going to store smallest prime factor 
    // of i. 
    int s[N+1]; 
  
    // Filling values in s[] using sieve 
    sieveOfEratosthenes(N, s);  
  
    int curr = s[N];  // Current prime factor of N 
    int cnt = 1;   // Power of current prime factor 
  
    // Printing prime factors and their powers
    long long int res=0; 
    while (N > 1) 
    { 
        N /= s[N]; 
  
        // N is now N/s[N].  If new N als has smallest 
        // prime factor as curr, increment power 
        if (curr == s[N]) 
        { 
            cnt++; 
            continue; 
        }  
        res=res+cnt;
        // Update current prime factor as s[N] and 
        // initializing count as 1. 
        curr = s[N]; 
        cnt = 1; 
    } 
    return res;
} 
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int x,k,r;
        cin>>x>>k;
        r = generatePrimeFactors(x);
        if(r==k)
        {
            cout<<1<<endl;
        } 
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}