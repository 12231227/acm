#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 100000;
ll ans[maxn + 11],s[maxn + 11],cf[maxn + 11];
vector <int> v[maxn + 11];
int l[maxn + 11];

char BUF[1 << 22], *ST, *EN;
#define gc (ST == EN && (ST = BUF, EN = BUF + fread(BUF, 1, 1 << 21, stdin), ST == EN) ? EOF : *ST++)
template<class T> void read(T &x){
	int f=0; x=0; char ch=gc;
	for(;!isdigit(ch);ch=gc) f|=(ch=='-');
	for(;isdigit(ch);ch=gc) x=x*10+ch-'0';
	if(f) x=-x;
}

ll gcd(ll a , ll b) { return b ? gcd(b , a % b) : a; }

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; read(t);
	while (t--) {
		int n,m; read(n); read(m);
		for (int i = 1; i <= m; i++) read(l[i]) , v[i].clear();
		for (int i = 1; i <= n; i++) {
			int a,b; read(a); read(b);
			v[b].pb(a);
		}
		for (int i = 1; i <= m; i++) sort(all(v[i]) , [&](int a,int b) { return a > b; });
		for (int i = 0; i <= n; i++) cf[i] = ans[i] = 0;
		for (int i = 1; i <= m; i++) {
			s[0] = 0;
			for (int j = 0; j < v[i].size(); j++) s[j + 1] = s[j] + v[i][j];
			int sz = v[i].size();
			//ans[sz] ~ ans[n] += sum
			cf[sz] += s[sz];
			for (int j = l[i]; j < sz; j++) ans[j] += s[j];
		} 
		for (int i = 1; i <= n; i++) cf[i] += cf[i - 1];
		for (int i = 1; i <= n; i++) ans[i] += cf[i];
		ll fz = 0 , fm = 1;
		for (int i = 1; i <= n; i++) {
			if (ans[i] * fm > fz * i) fz = ans[i] , fm = i;
		}
		ll g = gcd(fz , fm); fz /= g; fm /= g;
		printf("%lld/%lld\n" , fz , fm);
	} 
} 
