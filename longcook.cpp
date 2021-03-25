#include<iostream>
using namespace std;
#define f(i,x,n) for(int i=x;i<n;i++)
 
// 0 Sunday, 1 Monday... 6 Saturday
int day(int date, int month, int year)
{
	int yc = (year%100 + ((year%100)/4) )%7;
	int arr[] = {0,3,3,6,1,4,6,2,5,0,3,5};
	int mc = arr[month-1];
	int cc = 2* (3-((year/100)%4) );
	int dn = date;
	int lc = 0;
	if(month<=2 && ( (year%4==0 && year%100!=0) || (year%400==0) ))
		lc = 1;
	return (7+yc+mc+cc+dn-lc)%7;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int m1,y1,m2,y2,ans=0;
		cin>>m1>>y1>>m2>>y2;
		if(m1>2)
			y1++;
		if(m2<2)
			y2--;
		if(y2-y1<=400)
		{
			for(int i=y1;i<=y2;i++)
			{
				int d = day(1,2,i);
				if(d == 6)
					ans++;
				else if(d == 0 && (!( (i%4==0 && i%100!=0) || (i%400==0)) ) )
					ans++;
			}
			cout<<ans<<'\n';
			continue;
		}
		while(y1%400!=0)
		{
			int i=y1;
			int dy = day(1,2,i);
			if(dy == 6)
				ans++;
			else if(dy == 0 && (!( (i%4==0 && i%100!=0) || (i%400==0)) ) )
				ans++;
			y1++;
		}
		while(y2%400!=399)
		{
			int i=y2;
			int dy = day(1,2,i);
			if(dy == 6)
				ans++;
			else if(dy == 0 && (!( (i%4==0 && i%100!=0) || (i%400==0)) ) )
				ans++;
			y2--;	
		}
		cout<<ans+((y2-y1+1)/400)*101<<'\n';
	}
	
	return 0;
}