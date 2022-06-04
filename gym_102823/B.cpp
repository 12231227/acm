#include <bits/stdc++.h>
#define ll long long
#define uint unsigned int 
using namespace std;
const uint mode=998244353;
uint ig[(1<<20)+5],Ff[(1<<20)+5],lg[(1<<20)+5],tg[(1<<20)+5];
uint n,k;
uint F[(1<<20)+5],lF[(1<<20)+5],G[(1<<20)+5],f[(1<<20)+5];
uint pow_mul(uint x,uint y)
{
    uint ret=1;
    while(y)
    {
        if(y&1)ret=1ll*ret*x%mode;
        x=1ll*x*x%mode,y>>=1;
    }
    return ret;
}
uint MOD(uint x,uint y)
{
    return x+y>=mode?x+y-mode:x+y;
}
uint to[(1<<20)+5];
void NTT(uint *a,int len,int k)
{
    for(int i=0;i<len;i++)if(i<to[i])swap(a[i],a[to[i]]);
    for(int i=1;i<len;i<<=1)
    {
        uint w0=pow_mul(3,(mode-1)/(i<<1));
        for(int j=0;j<len;j+=(i<<1))
        {
            uint w=1;
            for(int o=0;o<i;o++,w=1ll*w*w0%mode)
            {
                uint w1=a[j+o],w2=1ll*a[j+o+i]*w%mode;
                a[j+o]=MOD(w1,w2),a[j+o+i]=(w1+mode-w2)%mode;
            }
        }
    }
    if(k==-1)
    {
        uint Inv=pow_mul(len,mode-2);
        for(int i=1;i<(len>>1);i++)swap(a[i],a[len-i]);
        for(int i=0;i<len;i++)a[i]=1ll*a[i]*Inv%mode;
    }
}
uint A[(1<<20)+5],B[(1<<20)+5],C[(1<<20)+5];
void mul(uint *f,uint *g,int len)
{
    int lim=1,l=0;
    while(lim<=2*len)lim<<=1,l++;
    for(int i=0;i<lim;i++)A[i]=B[i]=0,to[i]=((to[i>>1]>>1)|((i&1)<<(l-1)));
    for(int i=0;i<len;i++)A[i]=f[i],B[i]=g[i];
    NTT(A,lim,1),NTT(B,lim,1);
    for(int i=0;i<lim;i++)C[i]=1ll*A[i]*B[i]%mode;
    NTT(C,lim,-1);
}
void get_inv(uint *f,uint *g,int dep)
{
    if(dep==1)
    {
        g[0]=pow_mul(f[0],mode-2);
        return;
    }
    int nxt=(dep+1)>>1;
    get_inv(f,g,nxt);
    int lim=1,l=0;
    while(lim<=2*dep)lim<<=1,l++;
    for(int i=0;i<lim;i++)A[i]=B[i]=0,to[i]=((to[i>>1]>>1)|((i&1)<<(l-1)));
    for(int i=0;i<dep;i++)A[i]=f[i];
    for(int i=0;i<nxt;i++)B[i]=g[i];
    NTT(A,lim,1),NTT(B,lim,1);    
    for(int i=0;i<lim;i++)C[i]=1ll*A[i]*B[i]%mode*B[i]%mode;
    NTT(C,lim,-1);
    for(int i=0;i<dep;i++)g[i]=(2*g[i]+mode-C[i])%mode;
}
void get_ln(uint *f,uint *g,int dep)
{
    for(int i=0;i<dep;i++)ig[i]=0;
    get_inv(f,ig,dep);
    for(int i=0;i<dep-1;i++)Ff[i]=1ll*f[i+1]*(i+1)%mode;
    mul(ig,Ff,dep);
    for(int i=0;i<dep;i++)g[i+1]=1ll*C[i]*pow_mul(i+1,mode-2)%mode;
}
void get_exp(uint *f,uint *g,int dep)
{
    if(dep==1)
    {
        g[0]=1;
        return;
    }
    int nxt=(dep+1)>>1;
    get_exp(f,g,nxt);
    get_ln(g,lg,dep);
    for(int i=0;i<dep;i++)tg[i]=(f[i]+mode-lg[i])%mode;
    tg[0]++;
    mul(tg,g,dep);
    for(int i=0;i<dep;i++)g[i]=C[i];
}
template <typename T>inline void read(T &x)
{
    T f=1,c=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
    while(ch>='0'&&ch<='9'){c=MOD((uint)(1ll*c*10%mode),ch-'0');ch=getchar();}
    x=c*f;
}

int main(){ 
	int t; read(t);
	int cc = 0;
	while (t--) { 
		cc++;
		int l,k; read(n); read(l); read(k);
		memset(f , 0 , sizeof(f));
		for (int i = 0; i < n; i++) read(f[i]);
		reverse(f , f + n);
		memset(F , 0 , sizeof(F));
		for (int i = 0; i < l; i++) F[i] = 1;
		get_ln(F,lF,n);
    	for(int i=0;i<n;i++)lF[i]=1ll*lF[i]*k%mode;
    	get_exp(lF,G,n);
    	mul(f , G , n);
    	reverse(C , C + n);
    	printf("Case %d: " , cc);
    	for (int i = 0; i < n; i++) printf("%u " , C[i]); printf("\n");
	} 
} 
