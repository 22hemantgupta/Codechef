#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int s[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        long int sum=0;
        for(int i=1;i<n;i++)
        {
            int x=max(s[i-1],s[i]);
            int y=min(s[i-1],s[i]);
            sum=sum+(x-y-1);
        }
        cout<<sum<<endl;
    }
	// your code goes here
	return 0;
}
