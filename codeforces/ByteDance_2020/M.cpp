#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int mol = 998244353;
const int maxn = 4e5;
int cf[maxn + 11],sum[maxn + 11],l[maxn + 11],r[maxn + 11],s[maxn + 11],t[maxn + 11];

int add(int a,int b) { a += b; if (a >= mol) a -= mol; return a; }
int sub(int a,int b) { a -= b; if (a < 0) a += mol; return a; }
vector <int> v;

int qpow(int a,int b)  {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1ll * ans * a % mol;
		a = 1ll * a * a % mol;
		b >>= 1;
	}
	return ans;
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		v.pb(l[i]);
		v.pb(r[i]);
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> t[i];
		v.pb(s[i]);
		v.pb(t[i]);
	}
	sort(all(v)); v.erase(unique(all(v)) , v.end());
	for (int i = 1; i <= n; i++) {
		l[i] = lower_bound(all(v) , l[i]) - v.begin();
		r[i] = lower_bound(all(v) , r[i]) - v.begin();
		cf[l[i] + 1]++; cf[r[i] + 1]--;
		s[i] = lower_bound(all(v) , s[i]) - v.begin();
		t[i] = lower_bound(all(v) , t[i]) - v.begin();
		at[s[i] + 1]++; at[t[i] + 1]--;
	}
	for (int i = 1; i < v.size(); i++) cf[i] += cf[i - 1];
	for (int i = 1; i < v.size(); i++) at[i] += at[i - 1];
	sum[0] = 0;
	for (int i = 1; i < v.size(); i++) sum[i] = add(sum[i - 1] , at[i]);
	int ans = 0;
	int inv = qpow(n , mol - 2);
	for (int i = 2; i <= n; i++) { 
		int val = sub(sum[t[i]] , sum[s[i]]);
		ans = add(ans , 1ll * val * inv % mol);
	} 
	cout << ans << endl;
} 
