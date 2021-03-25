#include<iostream>
#include<cstdlib>
using namespace std;
int main() 
{
   int upper=1000000000;
   int lower=-1000000000;
   int max = 20; //set the upper bound to generate the random number
   srand(time(0));
   int a[6];
   int t=1000;
   cout<<t<<endl;
   while(t--)
   {
   for(int i=0;i<6;i++)
   {
        a[i]=(rand()%max)-10;
   }
   for(int i=0;i<3;i++)
   {
       cout<<a[i]<<" ";
   }
   cout<<endl;
   for(int i=3;i<6;i++)
   {
       cout<<a[i]<<" ";
   }
   cout<<endl;
   }
   return 0;
}