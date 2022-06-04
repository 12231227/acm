#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
using namespace std;

const int maxn = 2e6;
const ll mol = 1e9 + 7;
ll ans = 1;
ll inv[maxn + 11],fac[maxn + 11],cat[maxn + 11];
vector <int> v;
vector <int> pos[maxn + 11];
int a[maxn + 11];
set<int> s;

ll sub(ll a,ll b) { a -= b; if (a < 0) a += mol; return a; }
ll qpow(ll a,ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mol;
		a = a * a % mol;
		b >>= 1;
	}
	return ans;
} 

ll C(int n,int m) { return fac[n] * inv[m] % mol * inv[n - m] % mol; }

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	} 
	sort(all(v)); v.erase(unique (all(v)) , v.end());
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= 2 * n; i++) fac[i] = fac[i - 1] * i % mol;
	inv[2 * n] = qpow(fac[2 * n] , mol - 2);
	for (int i = 2 * n - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mol;
	for (int i = 1; i <= n; i++) {
		int ind = lower_bound(all(v) , a[i]) - v.begin();
		pos[ind].push_back(i);
	}
	cat[0] = 1;
	for (int i = 1; i <= n; i++) cat[i] = sub(C(2 * i , i) , C(2 * i , i - 1));
	s.insert(n + 1);
	for (int x = 0; x < v.size(); x++){
		int lim = *s.begin();
		int m = 0;
		for (auto p : pos[x]) {
			if (p > lim) {
				ans = ans * cat[m] % mol;
				lim = *s.lower_bound(p);
				m = 0;
			}
			m++;
		}
		ans = ans * cat[m] % mol;
		for (auto p : pos[x]) s.insert(p);
	}
	printf("%lld\n" , ans);
} 

