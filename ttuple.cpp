#include<bits/stdc++.h>
using namespace std;
float in = std::numeric_limits<float>::infinity();
double p,q,r,a,b,c;
int diff()
{
    long long int d1,d2,d3;
        d1=a-p;
        d2=b-q;
        d3=c-r;
        int res=0;
        if(d1==0 && d2==0 && d3==0)
        {
            //cout<<0<<endl;
            res=0;
        }
        else
        {
        if(d1==0)
        {
            if(d2!=0)
            {
                d1=d2;
            }
            else if(d3!=0)
            {
                d1=d3;
            }
        }
        if(d2==0)
        {
           if(d1!=0)
            {
                d2=d1;
            }
            else if(d3!=0)
            {
                d2=d3;
            } 
        }
        if(d3==0)
        {
           if(d1!=0)
            {
                d3=d1;
            }
            else if(d2!=0)
            {
                d3=d2;
            } 
        }
        if(d1==d2 && d1==d3)
        {
            res=1;
            //cout<<1<<endl;
        }
        else if((d1==d2 && d1!=d3) || (d2==d3 && d2!=d1) || (d1==d3 && d1!=d2)) 
        {
            res=2;
            //cout<<2<<endl;
        }
        else
        {
            res=3;
            //cout<<3<<endl;
        }
        }
        //cout<<res<<"  ";
    return res;
}
int div()
{
    long double d1,d2,d3;
    d1=a/p;
    d2=b/q;
    d3=c/r;
    if(a==0 && p==0)
    {
        d1=1;
    }
    if(b==0 && q==0)
    {
        d2=1;
    }
    if(c==0 && r==0)
    {
        d3=1;
    }
    //cout<<setprecision(20);
    //cout<<d1<<" "<<d2<<" "<<d3<<" ";
    int res=0;
    if(d1!=in && d2!=in && d3!=in)
    {
       // cout<<" gfgh"<<" ";
    if(d1==1)
        {
            //cout<<"gs"<<" ";
            if( d2==d3 && d2==(int)d2 && d3==(int)d3 )
            {
                res=1;
            }
            else 
            {
                res=2;
            }
        }
    else if(d2==1)
        {
           if(d1==d3 && d1==(int)d1 && d3==(int)d3)
            {
                res=1;
            }
            else 
            {
                res=2;
            } 
        }
    else if(d3==1)
        {
           if(d1==d2 && d1==(int)d1 && d2==(int)d2)
            {
                res=1;
            }
            else
            {
                res=2;;
            } 
        }
    else if(d1==d2 && d1==d3 && (d1==(int)d1 && d2==(int)d2 && d3==(int)d3))
        {
            //cout<<" hi";
            res=1;
            //cout<<1<<endl;
        }
    else if((d1==d2 && d1!=d3 && d1==(int)d1 && d2==(int)d2) || (d1==d3 && d1!=d2 && d1==(int)d1 && d3==(int)d3) || (d2==d3 && d2!=d1 && d2==(int)d2 && d3==(int)d3))
        {
            res=2;
            //cout<<2<<endl;
        }
    else
        {
            //cout<<"hi";
            res=3;
            //cout<<3<<endl;
        }
    }
    else
    {        
        if((d1==in && d2!=in && d3!=in))
        {
            if(d2==d3 && d2==(int)d2 && d3==(int)d3)
            {
                res=2;
            }
            else
            {
                res=3;
            }
            
        }
        else if(d1!=in && d2==in && d3!=in)
        {
            if(d1==d3 && d1==(int)d1 && d3==(int)d3)
            {
                res=2;
            }
            else
            {
                res=3;
            }
        }
        else if(d1!=in && d2!=in && d3==in)
        {
            if(d1==d2 && d1==(int)d1 && d2==(int)d2)
            {
                res=2;
            }
            else
            {
                res=3;
            }
        }
        else
        {
            res=diff();
        }
    }
       //cout<<res<<" ";
    return res;

}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>p>>q>>r;
        cin>>a>>b>>c;
        int res1=diff();
        int res2=div();
        int m=min(res1,res2);
        //cout<<m<<" ";
        if(m<3)
        {
            cout<<m<<endl;
        }
        else
        {
            long double x[3],y[3];
            bool flag=false;
            x[0]=p;
            x[1]=q;
            x[2]=r;
            y[0]=a;
            y[1]=b;
            y[2]=c;
            /*for(int i=0;i<3;i++)
            {
                float d1,d2;
                d2=x[(i+1)%3]/y[(i+1)%3];
                if( (x[(i+2)%3])*d2=y[(i+2)%3])
                {
                    flag=true;
                    break;
                }
            }*/
            cout<<setprecision(20);
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d2=y[(i+2)%3]/x[(i+2)%3];
                d1=(y[i]-((long double)x[i]*d2))/d2;
                //cout<<d1<<" "<<d2<<" ";
                if(d1==(int)d1 && d2==(int)d2)
                {
                if((x[(i+1)%3]+d1)==y[(i+1)%3])
                {
                    //cout<<d1<<" "<<d2<<" ";
                    flag=true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
               long double d1,d2;
                d2=y[(i+2)%3]/x[(i+2)%3];
                d1=(y[(i+1)%3]-((long double)x[(i+1)%3]*d2))/d2;
                if(d1==(int)d1 && d2==(int)d2)
                {
                if((x[(i)%3]+d1)==y[(i)%3])
                {
                    //cout<<d1<<" "<<d2<<" i2";
                    flag=true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d2=y[(i+2)%3]/x[(i+2)%3];
                d1=(y[i]-((long double)x[i]*d2))/d2;
                if(d1==(int)d1 && d2==(int)d2)
                {
                if(((x[(i+1)%3]+d1)*d2)==y[(i+1)%3])
                {
                    //cout<<d1<<" "<<d2<<" i3";
                    flag=true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d1=y[(i+2)%3]-x[(i+2)%3];
                d2=y[i]/(x[i]+d1);
                if(d1==(int)d1 && d2==(int)d2)
                {
                if((x[(i+1)%3]+d1)*d2==y[(i+1)%3])
                {
                    //cout<<d1<<" "<<d2<<" i4";
                    flag = true;
                    break;
                }
                }
            }
            for(int i=0;i<1;i++)
            {
                long double d1,d2;
                d1=((long double)((long double)x[i]*y[i+1])-((long double)x[i+1]*y[i]))/(y[i]-y[i+1]);
                d2=y[i]/(x[i]+d1);
                //cout<<d1<<" "<<d2<<" "<<(x[(i+2)%3]+d1)*d2<<" ";
                if(d1==(int)d1 && d2==(int)d2)
                {
                if(((x[i+2]+d1)*d2)==y[i+2])
                {
                    //cout<<d1<<" "<<d2<<" ";
                    flag = true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d2=y[(i+2)%3]-x[(i+2)%3];
                d1=(y[i]-d2)/x[i];
                //cout<<d1<<" "<<d2<<" ";
                if(d1==(int)d1 && d2==(int)d2)
                {
                if((x[(i+1)%3]*d1)==y[(i+1)%3])
                {
                    //cout<<d1<<" "<<d2<<" ";
                    flag=true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double  d1,d2;
                d2=y[(i+2)%3]-x[(i+2)%3];
                d1=(y[(i+1)%3]-d2)/x[(i+1)%3];
                //cout<<d1<<" "<<d2<<" ";
                if(d1==(int)d1 && d2==(int)d2)
                {
                if((x[(i)%3]*d1)==y[(i)%3])
                {
                    //cout<<d1<<" "<<d2<<" ";
                    flag=true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d2=y[(i+2)%3]-x[(i+2)%3];
                d1=(y[i]-d2)/x[i];
                if(d1==(int)d1 && d2==(int)d2)
                {
                if(((x[(i+1)%3]*d1)+d2)==y[(i+1)%3])
                {
                    flag=true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d1=y[(i+2)%3]/x[(i+2)%3];
                d2=y[i]-((long double)x[i]*d1);
                if(d1==(int)d1 && d2==(int)d2)
                {
                if((x[(i+1)%3]*d1)+d2==y[(i+1)%3])
                {
                    flag = true;
                    break;
                }
                }
            }
            for(int i=0;i<1;i++)
            {
                long double d1,d2;
                d1=((y[i+1]-y[i])/(x[i+1]-x[i]));
                d2=y[i]-((long double)x[i]*d1);
                if(d1==(int)d1 && d2==(int)d2)
                {
                // cout<<d1<<" "<<d2<<" "<<(x[(i+2)%3]+d1)*d2<<" ";
                if((x[i+2]*d1)+d2==y[i+2])
                {
                    //cout<<d1<<" "<<d2<<" ";
                    flag = true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d2=y[(i+2)%3]-x[(i+2)%3];
                d1=y[i]-x[i]-d2;
                //cout<<d1<<" "<<d2<<" ";
                if(d1==(int)d1 && d2==(int)d2)
                {
                if((x[(i+1)%3]+d1)==y[(i+1)%3])
                {
                    //cout<<d1<<" "<<d2<<" ";
                    flag=true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d2=y[(i+2)%3]-x[(i+2)%3];
                d1=y[(i+1)%3]-x[(i+1)%3]-d2;
                if(d1==(int)d1 && d2==(int)d2)
                {
                if((x[(i)%3]+d1)==y[(i)%3])
                {
                    //cout<<d1<<" "<<d2<<" i2";
                    flag=true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d2=y[(i+2)%3]-x[(i+2)%3];
                d1=y[i]-x[i]-d2;
                if(d1==(int)d1 && d2==(int)d2)
                {
                if(((x[(i+1)%3]+d1)+d2)==y[(i+1)%3])
                {
                    //cout<<d1<<" "<<d2<<" i3";
                    flag=true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d1=y[(i+2)%3]-x[(i+2)%3];
                d2=y[i]-(x[i]+d1);
                if(d1==(int)d1 && d2==(int)d2)
                {
                if((x[(i+1)%3]+d1)+d2==y[(i+1)%3])
                {
                    //cout<<d1<<" "<<d2<<" i4";
                    flag = true;
                    break;
                }
                }
            }
            /*for(int i=0;i<1;i++)
            {
                
                long double d1,d2;
                d1=((x[i]*y[i+1])-(x[i+1]*y[i]))/(y[i]-y[i+1]);
                d2=y[i]-(x[i]+d1);
                //cout<<d1<<" "<<d2<<" "<<(x[(i+2)%3]+d1)*d2<<" ";
                if(d1==(int)d1 && d2==(int)d2)
                {
                if(((x[i+2]+d1)*d2)==y[i+2])
                {
                    //cout<<d1<<" "<<d2<<" ";
                    flag = true;
                    break;
                }
                }
            }*/
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d2=y[(i+2)%3]/x[(i+2)%3];
                d1=(y[i]/((long double)x[i]*d2));
                //cout<<d1<<" "<<d2<<" ";
                if(d1==(int)d1 && d2==(int)d2)
                {
                if((x[(i+1)%3]*d1)==y[(i+1)%3])
                {
                    //cout<<d1<<" "<<d2<<" ";
                    flag=true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d2=y[(i+2)%3]/x[(i+2)%3];
                d1=(y[(i+1)%3]/((long double)x[(i+1)%3]*d2));
                if(d1==(int)d1 && d2==(int)d2)
                {
                if((x[i%3]*d1)==y[i%3])
                {
                    //cout<<d1<<" "<<d2<<" i2";
                    flag=true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d2=y[(i+2)%3]/x[(i+2)%3];
                d1=(y[i]/((long double)x[i]*d2));
                if(d1==(int)d1 && d2==(int)d2)
                {
                if(((x[(i+1)%3]*d1)*d2)==y[(i+1)%3])
                {
                    //cout<<d1<<" "<<d2<<" i3";
                    flag=true;
                    break;
                }
                }
            }
            for(int i=0;i<3;i++)
            {
                long double d1,d2;
                d1=y[(i+2)%3]/x[(i+2)%3];
                d2=y[i]/((long double)x[i]*d1);
                if(d1==(int)d1 && d2==(int)d2)
                {
                if((x[(i+1)%3]*d1)*d2==y[(i+1)%3])
                {
                    //cout<<d1<<" "<<d2<<" i4";
                    flag = true;
                    break;
                }
                }
            }
            /*for(int i=0;i<1;i++)
            {
                long double d1,d2;
                d1=((x[i]*y[i+1])-(x[i+1]*y[i]))/(y[i]-y[i+1]);
                d2=y[i]/(x[i]+d1);
                //cout<<d1<<" "<<d2<<" "<<(x[(i+2)%3]+d1)*d2<<" ";
                if(d1==(int)d1 && d2==(int)d2)
                {
                if(((x[i+2]+d1)*d2)==y[i+2])
                {
                    //cout<<d1<<" "<<d2<<" ";
                    flag = true;
                    break;
                }
                }
            }*/
            if(flag == true)
            {
                cout<<2<<endl;
            }
            else
            {
                cout<<3<<endl;
            }
        }
    }
    return 0;
}