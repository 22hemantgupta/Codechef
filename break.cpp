#include<iostream>
using namespace std;
int main()
{
        int T,res=0;
	cin>>T;
	while(T--)
	{
		int s,w1,w2,w3;
		cin>>s>>w1>>w2>>w3;
		if(s>=w1+w2+w3)
			res=1;
		else if(s>=w1+w2)
			res=2;
		else if(s>=w2+w3)
			res=2;
		else
			res=3;
		cout<<res<<endl;
        }
	return 0;
}
		


