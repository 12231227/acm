#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int mod=998244353;
namespace {
    inline int Add(int x,int y){return (x+=y)>=mod?x-mod:x;}
    inline int Sub(int x,int y){return (x-=y)<0?x+mod:x;}
    inline int Mul(int x,int y) {return 1ll*x*y%mod;}
    inline int Pow(int x,int y=mod-2){int res=1;while(y){if(y&1)res=1ll*res*x%mod;x=1ll*x*x%mod;y>>=1;}return res;}
};
namespace fft
{
    const int g=3;
    typedef unsigned long long ull;
    vector<int> rev;
    vector<ull> wn;
    void ensure_base(int nbase){
        rev.resize(1<<nbase);
        for(int i=0;i<(1<<nbase);i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(nbase-1));
        wn.resize(1<<nbase);
        wn[0]=1;
        int w=Pow(g,(mod-1)>>nbase);
        for(int i=1;i<(1<<nbase);i++)wn[i]=Mul(wn[i-1],w);
    }
    vector<ull> f;
    void ntt(vector<int> &a,int on){
        int sz=a.size();
        f.resize(sz);
        for(int i=0;i<sz;i++)f[i]=a[i];
        for(int i=0;i<sz;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
        for(int h=2,step=sz>>1;h<=sz;h<<=1,step>>=1){
            for(int j=0,m=h>>1;j<sz;j+=h){
                ull *l=f.data()+j,*r=f.data()+j+m,*w=wn.data();
                for(int k=0;k<h/2;k++,l++,r++,w+=step){
                    ull u=*l,t=*r* *w%mod;
                    *l=u+t,*r=u+mod-t;
                }
            }
        }
        for(int i=0;i<sz;i++)a[i]=f[i]%mod;
        if(on==-1){
            reverse(a.begin()+1,a.end());
            int invsz=Pow(sz,mod-2);
            for(int i=0;i<sz;i++)a[i]=Mul(a[i],invsz);
        }
    }
    vector<int> ff;
    vector<int> multiply_mod(vector<int> a,vector<int> b,int eq=1){ // 多项式相乘 
        int need=a.size()*eq+b.size()-1;
        if(need<128&&eq==1){
            ff.clear();
            ff.resize(need);
            for(int i=0;i<a.size();i++){
                for(int j=0;j<b.size();j++)ff[i+j]=Add(ff[i+j],Mul(a[i],b[j]));
            }
            return ff;
        }
        int nbase=0;
        while((1<<nbase)<need)nbase++;
        ensure_base(nbase);
        int sz=1<<nbase;
        a.resize(sz),b.resize(sz);
        ntt(a,1);ntt(b,1);
        for(int i=0;i<sz;i++)a[i]=Mul(eq==2?a[i]:1,Mul(a[i],b[i]));
        ntt(a,-1);
        a.resize(need);
        return a;
    }

};

namespace poly
{
    int inv(int x) {return Pow(x,mod-2);}
    vector<int> fa,fb,fc,fd;
    vector<int> get_inv(vector<int> a,int n)  // 多项式a求逆保留x^n以前 (及% x**n系下)
    {
        a.resize(n);
        if(n==1)
        {
            fa.resize(1);
            fa[0]=inv(a[0]);
            return fa;
        }
        fa=get_inv(a,(n+1)>>1);
        fb=fft::multiply_mod(fa,a,2);
        fa.resize(n);
        for(int i=0;i<n;i++)
        {
            fa[i]=Add(fa[i],fa[i]);
            fa[i]=Sub(fa[i],fb[i]);
        }
        return fa;
    }
};


vector <int> a , ans;

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	a.resize(5); ans.resize(5);
	a[1] = 1; a[0] = 998244352;
	ans = poly::get_inv(a , 5);
	for (int i = 0; i < 5; i++) cout << ans[i] << " ";
	cout << endl;
} 