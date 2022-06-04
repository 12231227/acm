#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

ll x,y;

struct out{
	int op; ll x,y;
};

vector <out> p;

ll exgcd(ll a,ll b,ll &x1,ll &y1) {
	if (!b) { x1 = 1; y1 = 0; return a; }
	ll x2,y2;
	ll d = exgcd(b , a % b , x2 , y2);
	x1 = y2; y1 = x2 - (a / b) * y2;
	return d;
} 

ll Add(ll x , ll cnt) {
	if (cnt == 1) return x;
	ll y = Add(x , cnt / 2);
	p.pb(out{0 , y , y});
	return y + y;
} 

ll solve(ll a,ll x) {
	ll ans = 0;
	for (int i = 0; ; i++) {
		if ((1ll << i) > x) break;
		ll t = Add(a , 1ll << i);
		if (ans) p.pb(out{0 , ans , t});
		if (x & (1ll << i)) ans += t;
	}
	return ans;
}

int main(){ 
	scanf("%lld",&x);
	int s = 0;
	for (int i = 0; ; i++) if ((1 << i) <= x) s = i; else break;
	ll t = Add(x , 1 << s);
	ll b = x ^ t;
	p.pb(out{1 , x , t});
	ll a = x;
	exgcd(a , b , x , y);
	x %= b;
	if (x < 0) x += b;
	if (x % 2 == 0) x += b;
	y = (a * x - 1) / b;
	ll X = solve(a , x);
	ll Y = solve(b , y);
	p.pb(out{1 , X , Y});
	printf("%d\n" , p.size());
	for (auto pi : p) {
		char c = pi.op ? '^' : '+';
		printf("%lld %c %lld\n" , pi.x , c , pi.y);
	}
} 
