#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tot = 0;
ll pp[1000];
ll read()
{
    ll f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

const int maxn=50001;
ll a[maxn],b[maxn],cnt;

ll qpow(ll ai,ll k,ll mod)
{
    ll mul=1;
    while(k>0)
    {
        if(k&1)mul=(mul*ai)%mod;
        ai=(ai*ai)%mod;
        k>>=1;
    }
    return mul;
}

ll fac(ll n,ll pi,ll pk)
{
    if(!n) return 1;
    ll mul=1;

    for(ll i=2;i<=pk;++i)//分解阶乘第二部分，循环节
    if(i%pi)mul=(mul*i)%pk;
    mul=qpow(mul,n/pk,pk);

    for(ll i=2;i<=n%pk;++i)//分解阶乘第三部分，求剩余数字
    if(i%pi)mul=(mul*i)%pk;

    return mul*fac(n/pi,pi,pk)%pk;//分解阶乘第一部分的另一个阶乘递归
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;return;
    }
    exgcd(b,a%b,x,y);
    ll tp=x;
    x=y; y=tp-a/b*y;
}
ll inv(ll a,ll b)
{
    ll x,y;
    exgcd(a,b,x,y);
    return (x%b+b)%b;
}

ll C(ll n,ll m,ll pi,ll ki,ll pk)
{
    ll facn=fac(n,pi,pk);//分别求n,m,n-m膜pi^ki的阶乘
    ll facm=fac(m,pi,pk);
    ll facnm=fac(n-m,pi,pk);
    ll kk=-ki*tot;
    for(ll i=n;i;i/=pi)kk+=i/pi;//上述分解阶乘第一部分的pi幂次方
    for(ll i=m;i;i/=pi)kk-=i/pi;
    for(ll i=n-m;i;i/=pi)kk-=i/pi;
    return facn*inv(facm,pk)%pk*inv(facnm,pk)%pk*qpow(pi,kk,pk)%pk;//注意求逆元
}
void div(ll n,ll m,ll x)
{
    for(ll i=2;i<=sqrt(x);++i)
    {
        if(x%i==0)
        {
            ll pi=i,ki=0;
            while(x%i==0)x/=i,ki++;
            b[++cnt]=qpow(pi,ki,2e7);
            pp[cnt] = ki;
            a[cnt]=C(n,m,pi,ki,b[cnt]);//C(n,m)%pi^ki
        }
    }
    if(x>1) {
        b[++cnt]=x,a[cnt]=C(n,m,x,1,b[cnt]); pp[cnt] = 1;
    } 
    for (ll i = 1; i <= cnt; i++) {
        for (ll j = 1; j <= cnt; j++){
            if (i == j) continue;
            a[i] = a[i] * qpow(qpow(b[j] , tot , b[i]) , b[i] - 2 , b[i]) % b[i];
        }
    }
}

ll exlucas()//china
{
    ll ans=0,M=1,x,y;
    for(int i=1;i<=cnt;++i) M*=b[i];
    for(int i=1;i<=cnt;++i)
    {
        ll tp=M/b[i];
        exgcd(tp,b[i],x,y);
        x=(x%b[i]+b[i])%b[i];
        ans=(ans+tp*x*a[i])%M;
    }
    return (ans+M)%M;
}

//for(ll i=n;i;i/=pi)kk+=i/pi;

int main()
{
    ll n=read(),m=read(),p=read();
    ll mn = 1000;
    ll tp = p;
    for (ll i = 2; i * i <= tp; i++) {
        if (tp % i == 0) {
        	ll ct = 0;
        	while (tp % i == 0) {
        		tp /= i; ct++;
			}
            ll cn = 0; ll cm = 0;
            for (ll j = n; j ; j /= i) cn += j / i;
            cn /= ct;
            for (ll j = m; j ; j /= i) cm += j / i;
            for (ll j = n - m; j ; j /= i) cm += j / i;
            cm /= ct;
            cn -= cm; if (cn < 0) cn = 0;
            mn = min(mn , cn);
        }
    }
    if (tp != 1) {
    	ll i = tp;
        ll cn = 0; ll cm = 0;
        for (ll j = n; j ; j /= i) cn += j / i;
        for (ll j = m; j ; j /= i) cm += j / i;
        for (ll j = n - m; j ; j /= i) cm += j / i;
        cn -= cm; if (cn < 0) cn = 0;
        mn = min(mn , cn);
	}
    tot = mn;
    div(n,m,p);
    printf("%lld",exlucas());
    return 0;
} 

