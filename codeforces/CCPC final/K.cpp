#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define TIMES 12

long long random(long long n)
{
    return (long long)((double)rand()/RAND_MAX*n+0.5);
}

long long multi(long long a,long long b,long long m)
{
    long long ans=0;

    while(b>0)
    {
        if(b&1)
            ans=(ans+a)%m;
        b>>=1;
        a=(a<<1)%m;
    }
    return ans;
}

long long quick_mod(long long a,long long b,long long m)
{
    long long ans=1;
    a%=m;

    while(b>0)
    {
        if(b&1)
        {
            ans=multi(ans,a,m);
            b--;
        }
        b>>=1;
        a=multi(a,a,m);
    }
    return ans;
}

bool witness(long long a,long long n)
{
    long long m=n-1;
    int j=0;

    while((m&1)==0)
    {
        j++;
        m>>=1;
    }

    long long x=quick_mod(a,m,n);

    if(x==1||x==n-1)
    {
        return false;
    }

    while(j--)
    {
        x=x*x%n;
        if(x==n-1) 
            return false;
    } 

    return true;
}

bool miller_rabin(long long n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0)return false;

    for(int i=1;i<=TIMES;i++)
    {
        long long a=random(n-2)+1;
        if(witness(a,n))
            return false;
    }
    return true;
}

int main(){
	 int t;
	 ll n,c;
	 scanf("%lld %lld",&n,&c);
	 ll sqr = sqrt(n);
	 ll p;
	 for (p = sqr + 1; ; p++) {
	 	if (miller_rabin(p)) break;
	 }
	 q = n / p;
     a = 1073741827 % (p - 1);
     b = c;
     b%=p;
     phi=p-1;
     work(phi);
     for(int i=1;i<=p;i++){
         bool flag=false;
         for(int j=1;j<=tot;j++)if(ksm(i,phi/prime[j])==1){flag=true;break;}
         if(flag==false){g=i;break;}
     }
     int r=BSGS(g,b);
     int gcd=exgcd(x,y,a,phi);
     //if(r%gcd!=0){printf("No Solution\n");continue;}
     x=x*r/gcd;
     int k=phi/gcd;
     x=(x%k+k)%k;
     num=0;
     while(x<phi){ans[++num]=ksm(g,x),x+=k;}
     sort(ans+1,ans+1+num);
     for(int i=1;i<=num;i++)printf("%lld ",ans[i]);
     printf("\n");
    return 0;
}
