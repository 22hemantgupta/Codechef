#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int divide(long long int x , long long int y)
{
    if(y==0LL)
     return 0LL;
    else
    {
        return (long long int)x/(long long int)y;
    }
    
}
int diff(ll p,ll q, ll r,ll a, ll b , ll c)
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
            //flag=true;
        }
        else if(d1==d2+d3 || d2==d1+d3 || d3==d1+d2)
        {
            res=2;
        }
        else
        {
            res=3;
            //cout<<3<<endl;
        }
        }
       // cout<<res<<"  ";
    return res;
}
int div(ll p,ll q, ll r,ll a, ll b , ll c)
{
    long long int d1,d2,d3;
    int res=0;
    if (r==c&&q==b&&(p!=0)&&a%p==0){
        res=1;
    }
    else if (p==a&&r==c&&(q!=0)&&b%q==0){
        res=1;
    }
    else if (p==a&&q==b&&(r!=0)&&c%r==0){
        res=1;
    }
    else if (r==c&&(q!=0)&&(p!=0)&&(a%p==0)&&(b%q==0)&&a/p==b/q){
        res=1;
    }
    else if (q==b&&(r!=0)&&(p!=0)&&(a%p==0)&&(c%r==0)&&a/p==c/r){
        res=1;
    }
    else if (p==a&&(q!=0)&&(r!=0)&&(c%r==0)&&(b%q==0)&&c/r==b/q){
        res=1;
    }
    else if (p!=0&&q!=0&&r!=0&&(a%p==0)&&(b%q==0)&&(c%r==0)&&a/p==b/q&&b/q==c/r){
        res=1;
    }
    else
    {
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
    if(p!=0 && q!=0 && r!=0)
    {
        d1=a/p;
        d2=b/q;
        d3=c/r;
       // cout<<" gfgh"<<" ";
    if(d1==1 && a%p==0 && d2==1 && b%q==0 && d3==1 && c%r==0)
    {
        res=1;
    }
    else if(d1==1 && a%p==0)
        {
            //cout<<"gs"<<" ";
            if( d2==d3 && (b%q==0) && (c%r==0) )
            {
                res=1;
            }
            else 
            {
                res=2;
            }
        }
    else if(d2==1 && b%q==0)
        {
           if(d1==d3 && a%p==0 && c%r==0)
            {
                res=1;
            }
            else 
            {
                res=2;
            } 
        }
    else if(d3==1 && c%r==0)
        {
           if(d1==d2 && a%p==0 && b%q==0)
            {
                res=1;
            }
            else
            {
                res=2;;
            } 
        }
    else if(d1==d2 && d1==d3 && a%p==0 && c%r==0 && b%q==0)
        {
            //cout<<" hi";
            res=1;
            //cout<<1<<endl;
        }
    else if((d1==d2 && d1!=d3 && a%p==0 && b%q==0) || (d1==d3 && d1!=d2 && a%p==0 && c%r==0) || (d2==d3 && d2!=d1 && b%q==0 && c%r==0))
        {
            res=2;
            //flag=true;
        }
    else
        {
            //cout<<"hi";
            res=diff(p,q,r,a,b,c);
            //cout<<3<<endl;
        }
    }
    else
    {        
        if((p==0 && a!=0 && q!=0 && r!=0))
        {
            d2=b/q;
            d3=c/r;
            if(d2==d3 && b%q==0 && c%r==0)
            {
                res=2;
            }
            else
            {
                res=3;
            }
            
        }
        else if(p!=0 && q==0 && b!=0 && r!=0)
        {
            d1=a/p;
            d3=c/r;
            if(d1==d3 && a%p==0 && c%r==0)
            {
                res=2;
            }
            else
            {
                res=3;
            }
        }
        else if(p!=0 && q!=0 && c!=0 && r==0)
        {
            d1=a/p;
            d2=b/q;
            if(d1==d2 && a%p==0 && b%q==0)
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
            res=diff(p,q,r,a,b,c);
        }
    }
    }
       //cout<<res<<" ";
    return res;

}
int iftwo(ll p, ll q, ll r, ll a, ll b, ll c)
{
    ll x,y;
    if (p==a||q==b||r==c){
        return 2;
    }
    if ((a-p==b-q)||(b-q==c-r)||(a-p==c-r)){
        return 2;
    }

    if ((p!=0&&q!=0)&&(a%p==0&&b%q==0&&a/p==b/q)||(q!=0&&r!=0)&&(b%q==0&&c%r==0&&b/q==c/r)||(p!=0&&r!=0)&&(a%p==0&&c%r==0&&a/p==c/r)){
        return 2;
    }

    if (p+b-q+c-r==a){
        return 2;
    }
   // if (a==b&&b==c){
    //    return 2;
    //}

    if(p!=q &&(a-b)%(p-q)==0)
   {
       x=(a-b)/(p-q);
       y=b-q*x;
       assert(b-q*x==a-p*x);
       if(r*x==c || r*x+y==c || r+y==c)
       {//cout<<"f7";
       return 2;}
   }
    if(q!=0&&b%q==0)
   {
       x=b/q;
       y=a-p*x;
       if(r*x==c||r+y==c||r*x+y==c)
       {return 2;}
   }
   if(r!=0&&c%r==0)
   {
       x=c/r;
       y=a-p*x;
       if(q*x==b||q+y==b||q*x+y==b)
       {return 2;}
   }
   if(r!=q &&(c-b)%(r-q)==0)
   {
       x=(c-b)/(r-q);
       y=b-q*x;
       assert(b-q*x==c-r*x);
       if(p*x==a || p*x+y==a || p+y==a)
       {//cout<<"f15";
       return 2;}
   }
   if(r!=0&&c%r==0)
   {
       x=c/r;
       y=b-q*x;
       if(p*x==a||p+y==a||p*x+y==a)
       {return 2;}
   }
   if(p!=0&&a%p==0)
   {
       x=a/p;
       y=b-q*x;
       if(r*x==c||r+y==c||r*x+y==c)
       {return 2;}
   }
   if(p!=r &&(a-c)%(p-r)==0)
   {
       x=(a-c)/(p-r);
       y=a-p*x;
       assert(c-r*x==a-p*x);
       if(q*x==b || q*x+y==b || q+y==b)
       {//cout<<"f8";
       return 2;}
   }
   if(p!=0&&a%p==0)
   {
       x=a/p;
       y=c-r*x;
       if(q*x==b||q+y==b||q*x+y==b)
       {return 2;}
   }
   if(q!=0&&b%q==0)
   {
       x=b/q;
       y=c-r*x;
       if(p*x==a||p+y==a||p*x+y==a)
       {return 2;}
   }
   //(p+x)y=a
   if(a!=b &&(p*b-a*q)%(a-b)==0)
   {
       x=(p*b-a*q)/(a-b);
       if(q+x!=0)
       {y=b/(q+x);
       if(r+x==c || r*y==c ||(r+x)*y==c)
       {//cout<<"f9";
       return 2;}
       }
   }
   x=(b-q);
   if(p+x!=0 &&a%(p+x)==0)
   {
       y=a/(p+x);
       if((r+x==c || r*y==c ||(r+x)*y==c)&&(q+x==b||q*y==b||(q+x)*y==b))
       {//cout<<"f9";
       return 2;}
   }
   x=c-r;
   if(p+x!=0 &&a%(p+x)==0)
   {
       y=a/(p+x);
       if((r+x==c || r*y==c ||(r+x)*y==c)&&(q+x==b||q*y==b||(q+x)*y==b))
       {//cout<<"f9";
       return 2;}
   }
    if(c!=b &&(r*b-c*q)%(c-b)==0)
   {
       x=(r*b-c*q)/(c-b);
       if(q+x!=0)
       {y=b/(q+x);
       if(p+x==a || p*y==a ||(p+x)*y==a)
       {//cout<<"f10";
       return 2;}
       }
   }
   x=(b-q);
   if(r+x!=0 &&c%(r+x)==0)
   {
       y=c/(r+x);
       if((p+x==a || p*y==a ||(p+x)*y==a)&&(q+x==b||q*y==b||(q+x)*y==b))
       {//cout<<"f9";
       return 2;}
   }
   x=a-p;
   if(p+x!=0 &&a%(p+x)==0)
   {
       y=a/(p+x);
       if((p+x==a || p*y==a ||(p+x)*y==a)&&(q+x==b||q*y==b||(q+x)*y==b))
       {//cout<<"f9";
       return 2;}
   }
   if(a!=c &&(p*c-a*r)%(a-c)==0)
   {
       x=(p*c-a*r)/(a-c);
       if(p+x!=0)
       {y=a/(p+x);
       if(q+x==b || q*y==b ||(q+x)*y==b)
       {//cout<<"f11";
        return 2;}
       }
   }
   x=(c-r);
   if(q+x!=0 &&b%(q+x)==0)
   {
       y=b/(q+x);
       if((p+x==a || p*y==a ||(p+x)*y==a)&&(r+x==c||r*y==c||(r+x)*y==c))
       {//cout<<"f9";
       return 2;}
   }
   x=a-p;
   if(q+x!=0 &&a%(q+x)==0)
   {
       y=b/(q+x);
       if((p+x==a || p*y==a ||(p+x)*y==a)&&(r+x==c||r*y==c||(r+x)*y==c))
       {//cout<<"f9";
       return 2;}
   }
   //a=p*x*y 
   if(q!=0 && b%q==0)
   {
       y=b/q;
       if(p!=0 && y!=0)
      { x=a/(p*y);
       if(r*x==c || r*y==c ||r*x*y==c)
       {//cout<<"f12";
       return 2;}
      }
   }
   if(r!=0 && c%r==0)
   {
       y=c/r;
       if(q!=0 && y!=0)
       {x=b/(q*y);
       if(p*x==a || p*y==a ||p*x*y==a)
       {//cout<<"f13";
       return 2;}
       }
   }
   if(p!=0 && a%p==0)
   {
       y=a/p;
       if(r!=0 && y!=0)
       {x=c/(r*y);
       if(q*x==b || q*y==b ||q*x*y==b)
       {//cout<<"f14";
       return 2;}
       }
   }
  //p+x=a
  x=a-p;
  y=b-q-x;
  if(r+x+y==c || (r+x)*y==c||r+y==c||r*y==c)
  {return 2;}
  if(q+x!=0 && b%(q+x)==0)
  {y=b/(q+x);
      if(r+x+y==c || (r+x)*y==c||r+y==c||r*y==c)
      {return 2;}
  }
  y=b-q;
  if(r+x+y==c || (r+x)*y==c||r+y==c||r*y==c)
  {return 2;}
    if(q!=0 && b%q==0)
    {
        y=b/q;
        if(r+x+y==c || (r+x)*y==c||r+y==c||r*y==c)
        {return 2;}
    }
    //px=a
    if(p!=0 && a%p==0)
    {
        x=a/p;
        y=b-q*x;
        if(r*x+y==c||r*x*y==c||r+y==c||r*y==c)
        {return 2;}
        if(q*x!=0 && b%(q*x)==0)
        {
            y=b/(q*x);
            if(r*x+y==c||r*x*y==c||r+y==c||r*y==c)
            {return 2;}
        }
        y=b-q;
        if(r*x+y==c||r*x*y==c||r+y==c||r*y==c)
        {return 2;}
        if(q!=0)
        {
            y=b/q;
            if(r*x+y==c||r*x*y==c||r+y==c||r*y==c)
            {return 2;}
        }
    }
    //p+y==a
    y=a-p;
    x=b-q-y;
    if(r+x+y==c||r+x==c||r*x+y==c||r*x==c)
    {return 2;}
    x=b-q;
    if(r+x+y==c||r+x==c||r*x+y==c||r*x==c)
    {return 2;}
    if(q!=0&&(b-y)%q==0)
    {
      x=(b-y)/q;
      if(r+x+y==c||r+x==c||r*x+y==c||r*x==c)
      {return 2;}
    }
    if(q!=0&&(b)%q==0)
    {
      x=(b)/q;
      if(r+x+y==c||r+x==c||r*x+y==c||r*x==c)
      {return 2;}
    }
    //py=a
    if(p!=0&&a%p==0)
    {
        y=a/p;
        if(y!=0&&b%y==0)
        {x=(b/y)-q;
            if((r+x)*y==c||r+x==c||r*x+y==c||r*x==c)
            {return 2;}
        }
        x=b-q;
        if((r+x)*y==c||r+x==c||r*x+y==c||r*x==c)
            {return 2;}
        if(q*y!=0&&b%(q*y)==0)
        {
            x=b/(q*y);
            if((r+x)*y==c||r+x==c||r*x+y==c||r*x==c)
            {return 2;}
        }
        if(q!=0&&b%(q)==0)
        {
            x=b/(q);
            if((r+x)*y==c||r+x==c||r*x+y==c||r*x==c)
            {return 2;}
        }
    }
    return 3;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        long long int p,q,r,a,b,c;
        cin>>p>>q>>r;
        cin>>a>>b>>c;
        int res1=diff(p,q,r,a,b,c);
        int res2=div(p,q,r,a,b,c);
        int m=min(res1,res2);
        //cout<<m<<" ";
        if(m<3)
        {
            cout<<m<<endl;
        }
        else
        {
            long long int x[4],y[4];
            bool flag=false;
            x[0]=p;
            x[1]=q;
            x[2]=r;
            y[0]=a;
            y[1]=b;
            y[2]=c;
            int ans=iftwo(p,q,r,a,b,c);
            /*for(int i=0;i<3;i++)
            {
                long long int d1,d2;
                d2=divide(y[(i+2)%3],x[(i+2)%3]);
                d1=y[(i+1)%3]-x[(i+1)%3];
                if(y[(i+1)%3]==(x[(i+1)%3]+d1) && y[(i+2)%3]==(x[(i+2)%3]*d2) && y[(i)%3]==((x[(i)%3]+d1)*d2))
                {
                    flag=true;
                    break;
                }
            }
            for(int i=0;i<3;i++)
            {
               long long int d1,d2;
                d2=divide(y[(i+2)%3],x[(i+2)%3]);
                d1=y[i]-x[i];
                if((x[i]+d1)==y[i] && (x[(i+2)%3]*d2)==y[(i+2)%3] && ((x[(i+1)%3]+d1)*d2)==y[(i+1)%3])
                {
                    flag=true;
                    break;
                }
            }
            for(int i=0;i<3;i++)
            {
                long long int d1,d2;
                d2=divide(y[(i+2)%3],x[(i+2)%3]);
                d1=divide(y[i],d2) - x[i];
                if(((x[(i+1)%3]+d1)*d2)==y[(i+1)%3] && x[(i+2)%3]*d2==y[(i+2)%3] && (x[i]+d1)*d2==y[i])
                {
                   // cout<<d1<<" "<<d2<<" i4";
                    flag=true;
                    break;
                }
            }
            for(int i=0;i<3;i++)
            {
                long long int d1,d2;
                d1=y[(i+2)%3]-x[(i+2)%3];
                d2=divide(y[i],(x[i]+d1));
                if((x[(i+1)%3]+d1)*d2==y[(i+1)%3] && x[(i+2)%3]+d1==y[(i+2)%3] && (x[(i)%3]+d1)*d2==y[(i)%3])
                {
                   // cout<<d1<<" "<<d2<<" i5";
                    flag=true;
                    break;
                }
            }
            for(int i=0;i<1;i++)
            {
                long long int d1,d2;
                ll h=y[i]-y[i+1];
                ll g=(x[i]-x[i+1]);
                d2=divide(h,g);
                d1=divide(y[i],d2)-x[i];
                if(y[i+2]==((x[i+2]+d1)*d2) && y[(i)%3]==((x[(i)%3]+d1)*d2) && y[(i+1)%3]==((x[(i+1)%3]+d1)*d2))
                {
                   // cout<<d1<<" "<<d2<<" i6";
                    flag=true;
                    break;
                }
            }
            for(int i=0;i<3;i++)
            {
                long long int d1,d2;
                d2=y[(i+2)%3]-x[(i+2)%3];
                d1=divide(y[(i+1)%3],x[(i+1)%3]);
                if((x[(i+1)%3]*d1)==y[(i+1)%3] && x[(i+2)%3]+d2==y[(i+2)%3] && (x[(i)%3]*d1)+d2==y[(i)%3])
                {
                  // cout<<d1<<" "<<d2<<" i7";
                    flag=true;
                    break;
                }
            }
            for(int i=0;i<3;i++)
            {
                long long int  d1,d2;
                d2=y[(i+2)%3]-x[(i+2)%3];
                d1=divide(y[i%3],x[i%3]);
                //cout<<d1<<" "<<d2<<" ";
                if((x[(i)%3]*d1)==y[(i)%3] && x[(i+2)%3]+d2==y[(i+2)%3] && (x[(i+1)%3]*d1)+d2==y[(i+1)%3])
                {
                   // cout<<d1<<" "<<d2<<" i8";
                    flag=true;
                    break;
                }
            }
            for(int i=0;i<3;i++)
            {
                long long int d1,d2;
                d2=y[(i+2)%3]-x[(i+2)%3];
                d1=divide((y[i]-d2),x[i]);
                if(((x[(i+1)%3]*d1)+d2)==y[(i+1)%3] && x[(i+2)%3]+d2==y[(i+2)%3] && (x[(i)%3]*d1)+d2==y[(i)%3])
                {
                   // cout<<d1<<" "<<d2<<" i9";
                    flag=true;
                    break;
                }
            }
            for(int i=0;i<3;i++)
            {
                long long int d1,d2;
                d1=divide(y[(i+2)%3],x[(i+2)%3]);
                d2=y[i]-(x[i]*d1);
                if((x[(i+1)%3]*d1)+d2==y[(i+1)%3] && x[(i+2)%3]*d1==y[(i+2)%3] && (x[(i)%3]*d1)+d2==y[(i)%3])
                {
                   // cout<<d1<<" "<<d2<<" i10";
                    flag=true;
                    break;
                }
            }
            for(int i=0;i<1;i++)
            {
                long long int d1,d2;
                ll h=y[i]-y[i+1];
                ll g=(x[i]-x[i+1]);
                d1=divide(h,g);
                d2=y[i]-(x[i]*d1);
                if(y[i+2]==((x[i+2]*d1)+d2) && y[(i+1)%3]==((x[(i+1)%3]*d1)+d2) && y[(i)%3]==((x[(i)%3]*d1)+d2))
                {
                    //cout<<d1<<" "<<d2<<" ";
                    flag=true;
                    break;
                }
            }
            for(int i=0;i<3;i++)
            {
                long long int d1,d2;
                d2=divide(y[(i+2)%3],x[(i+2)%3]);
                d1=divide(y[(i+1)%3],(x[(i+1)%3]));
                //cout<<d1<<" "<<d2<<" ";
                if((x[(i+1)%3]*d1)==y[(i+1)%3] && x[(i+2)%3]*d2==y[(i+2)%3] && x[(i)%3]*d1*d2==y[(i)%3])
                {
                    //cout<<d1<<" "<<d2<<" ";
                    flag=true;
                    break;
                }
            }
            for(int i=0;i<3;i++)
            {
                long long int d1,d2;
                d2=divide(y[(i+2)%3],x[(i+2)%3]);
                d1=divide(y[(i)%3],(x[(i)%3]));
                if((x[i%3]*d1)==y[i%3] && x[(i+2)%3]*d2==y[(i+2)%3] && x[(i+1)%3]*d1*d2==y[(i+1)%3])
                {
                    //cout<<d1<<" "<<d2<<" i2";
                    flag=true;
                    break;
                }
            }*/
            cout<<ans<<endl;
            
        }
    }
    return 0;
}