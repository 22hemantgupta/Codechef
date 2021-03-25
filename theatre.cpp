#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    long int sum=0;
    cin>>T;
    while(T--)
    {
        int N,arr[5][5];
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                arr[i][j]=0;
            }
        }
        cin>>N;
	    vector<vector<int> > v(24);
        while(N--)
        {
            int t;
            char m;
            cin>>m;
	        cin>>t;
            int r=t/3;
            if(m == 'A')
            {
                arr[1][r]++;
            }
            else if(m == 'B')
            {
                arr[2][r]++;
            }
            else if(m == 'C')
            {
                arr[3][r]++;
            }  
            else
            {
                arr[4][r]++;
            }
        }
        /*for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }*/
        int z=1,k=0;
        for(int i=1;i<=4;i++)
        {
            //v.push_back ( vector<int>() );
            for(int j=1;j<=4;j++)
            {
                    if(j!=i)
                    {
                        for(int p=1;p<=4;p++) 
                        {
                            if(p!=i && p!=j)
                            {
                                for(int q=1;q<=4;q++)
                                {
                                    if(q!=i && q!=j && q!=p)
                                    {
                                        v[k].push_back(arr[1][i]);
                                        v[k].push_back(arr[2][j]);
                                        v[k].push_back(arr[3][p]);
                                        v[k].push_back(arr[4][q]);
                                        k++;
                                    }
                                }
                            }
                        }
                    }
            }
        }
        for(int i=0;i<k;i++)
        {
            sort(v[i].begin(),v[i].end());

        }
        //sort(v.begin(),v.end());
        int count[k]={0};
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(v[i][j]==0)
                count[i]++;
            }
        }
        long int max1=INT16_MIN;
        for(int i=0;i<k;i++)
        {
            long int w = ((v[i][0]*25)+(v[i][1]*50)+(v[i][2]*75)+(v[i][3]*100) - (count[i]*100));
            if(w>max1)
            {
                max1=w;
            }
        }
        cout<<max1<<endl;
        sum=sum+max1;
        //sort(v.begin(),v.end());
    }
    cout<<sum<<endl;
    return 0;
}
