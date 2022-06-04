#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const ll inf = 4e18;

char BUF[1 << 22], *ST, *EN;
#define gc (ST == EN && (ST = BUF, EN = BUF + fread(BUF, 1, 1 << 21, stdin), ST == EN) ? EOF : *ST++)
 
template<class T> void read(T &x){
	int f=0; x=0; char ch=gc;
	for(;!isdigit(ch);ch=gc) f|=(ch=='-');
	for(;isdigit(ch);ch=gc) x=x*10+ch-'0';
	if(f) x=-x;
}

vector <int> v,p,l,r,L,R;

ll solve(vector <int> l,vector <int> r,vector <int> v) { 
	ll ans = inf;
	ll sl = 0 , sr = 0;
	int i = 0 , j = 0;
	for (auto u : l) sl += u;
	for (auto x : v) { 
		while (j < r.size() && r[j] < x) sr += r[j++];
		while (i < l.size() && l[i] <= x) sl -= l[i++];
		ans = min(ans , 1ll * x * j + sl - sr - 1ll * x * ((int)l.size() - i));
	} 
	return ans;
} 

int main(){ 
	int t; read(t);
	while (t--) {
		int n; read(n);
		v.clear(); p.clear(); l.clear(); r.clear(); L.clear(); R.clear();
		for (int i = 1; i <= n; i++) { 
		
			int a,b,c,d; read(a); read(b); read(c); read(d);
			l.pb(a); L.pb(b);
			r.pb(c); R.pb(d);
			v.pb(a); v.pb(c);
			p.pb(b); p.pb(d);
		} 
		sort(all(l)); sort(all(L));
		sort(all(r)); sort(all(R));
		sort(all(v)); sort(all(p));
		printf("%lld\n" , solve(l , r , v) + solve(L , R , p));
	} 
} 

