#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 3e5;
vector <int> bp[maxn + 11];
int fa[maxn + 11],a[maxn + 11];
unordered_map <int,int> mp[maxn + 11];

ll ans = 0;

int gcd(int a,int b) { return b == 0 ? a : gcd(b , a % b); } 
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }

void insert(int x,int y) {
	for (auto pi : mp[x]) {
		int u = pi.first;
		for (auto p : bp[u]) if (mp[y].count(p)) ans += 1ll * pi.second * mp[y][p];
	} 
	for (auto pi : mp[x]) {
		int u = pi.first;
		mp[y][u] += pi.second;
	}
} 

void merge(int x,int y) {
	int fax = get(x) , fay = get(y);
	if (fax == fay) return;
	if (mp[fax].size() <= mp[fay].size()) {
		insert(fax , fay);
		fa[fax] = fay;
	}
	else {
		insert(fay , fax);
		fa[fay] = fax;
	} 
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n = 2e5;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i) {
			if (j + i <= n && gcd(j + i , j) == i && ((j + i) ^ j) == i) {
				bp[j].pb(j + i); bp[j + i].pb(j);
			}
		}
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i] , mp[i][a[i]] = 1;
	for (int i = 1; i <= n + m; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int op; cin >> op;
		if (op == 1) {
			int x,v; cin >> x >> v;
			a[x] = v; mp[x][v] = 1;
		}
		else if (op == 2){
			int x,y; cin >> x >> y;
			merge(x , y);
		} 
		else {
			int x,v; cin >> x >> v;
			int fax = get(x);
			--mp[fax][a[x]];
			for (auto u : bp[a[x]]) if (mp[fax].count(u)) ans -= mp[fax][u];
			a[x] = v;
			for (auto u : bp[a[x]]) if (mp[fax].count(u)) ans += mp[fax][u];
			++mp[fax][a[x]];
		} 
		printf("%lld\n" , ans);
	} 
} 
