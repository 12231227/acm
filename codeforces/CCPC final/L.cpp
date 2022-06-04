#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
#define TIMES 12
int prime[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int ans5[305][5];
int ans6[305][6];

bool isprime(long long p) { 
 for (int i = 2; i <= sqrt(p); i++) { 
  if (i % p == 0)
   return false;
 } 
 return true;
} 
void init() {
 for (int i1 = 0; i1 < 25; i1++) {
  for (int i2 = 0; i2 < 25; i2++) {
   for (int i3 = 0; i3 < 25; i3++) {
    for (int i4 = 0; i4 < 25; i4++) { 
     for (int i5 = 0; i5 < 25; i5++) { 
      for (int i6 = 0; i6 < 25; i6++) {
       int pp = prime[i1] + prime[i2] + prime[i3] + prime[i4] + prime[i5] + prime[i6];
       if (pp > 300)
        continue;
       ans6[pp][0] = prime[i1];
       ans6[pp][1] = prime[i2];
       ans6[pp][2] = prime[i3];
       ans6[pp][3] = prime[i4];
       ans6[pp][4] = prime[i5];
       ans6[pp][5] = prime[i6];
      }
     }
    }
   }
  }
 }
 for (int i1 = 0; i1 < 25; i1++) {
  for (int i2 = 0; i2 < 25; i2++) {
   for (int i3 = 0; i3 < 25; i3++) {
    for (int i4 = 0; i4 < 25; i4++) {
     for (int i5 = 0; i5 < 25; i5++) {
      int pp = prime[i1] + prime[i2] + prime[i3] + prime[i4] + prime[i5];
      if (pp > 300)
       continue;
      ans5[pp][0] = prime[i1];
      ans5[pp][1] = prime[i2];
      ans5[pp][2] = prime[i3];
      ans5[pp][3] = prime[i4];
      ans5[pp][4] = prime[i5];
     }
    }
   }
  }
 }
}
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

int main() {
 //freopen("in.txt" , "r" , stdin);
 init();
 int T;
 scanf("%d", &T);
 for (int j = 1; j <= T; j++) {
  long long n;
  scanf("%lld", &n);
  if (n <= 11)
   printf("Case %d: IMPOSSIBLE\n", j);
  else if (n <= 300) {
   printf("Case %d:", j);
   for (int i = 0; i <= 5; i++) {
    printf(" %d", ans6[n][i]);
   }
   printf("\n");
  }
  else {
  	printf("Case %d: ", j);
  	ll x = n - 10;
  	for ( ; ; x--) {
  		if (miller_rabin(x)) break;
  	}
  	printf("%lld " , x);
  	for (int i = 0; i <= 4; i++) printf("%d%s",ans5[n - x][i] , i == 4 ? "\n" : " ");
  }
 }
}
