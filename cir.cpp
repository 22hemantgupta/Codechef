#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
   while(t--){
    int n,i,j;
    cin>>n;

    int a[n],b[n];

    for(i=0;i<n;i++){

            cin>>a[i];
       }
    for(i=0;i<n;i++){

            cin>>b[i];
       }

    sort(a,a+n);
    sort(b,b+n);

   int sum=0;
    for(i=0;i<n;i++){

        if(a[i]>b[i])
        {
            sum= sum+ b[i];
        }

        else
                sum=sum+a[i];
    }
    cout<<sum<<endl;
   }
   return 0;
}
