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
const int maxn = 4e5;

vector <int> g[maxn + 11];
int deg[maxn + 11],e[maxn + 11],cnt[maxn + 11],pos[maxn + 11],Deg[maxn + 11];
int n;

void topo() {
	for (int i = 1; i <= n; i++) Deg[i] = deg[i];
	queue <int> q; q.push(0);
	while (!q.empty()) { 
		int x = q.front(); q.pop();
		for (auto u : g[x]) { 
			pos[u] = min(pos[x] , pos[u]);
			if (--Deg[u] == 0) q.push(u);
		} 
	} 
} 

bool check(int tim) { 
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i++) { 
		if (tim - e[i] + 1 <= 0) return false;
		pos[i] = min(tim - e[i] + 1 , n);
	} 
	topo();
	for (int i = 1; i <= n; i++) cnt[pos[i]]++;
	int res = 0;
	for (int i = 1; i <= n; i++) { 
		res++;
		if (cnt[i] > res) return false;
		res -= cnt[i];
	} 
	return true;
} 

int main(){ 
	scanf("%d",&n);
	int l = 0 , r = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d %d",&e[i],&k);
		r = max(e[i] + n - 1 , r);
		l = max(l , e[i]);
		for (int j = 1; j <= k; j++) { int x; scanf("%d",&x); g[i].pb(x); deg[x]++; } 
	} 
	for (int i = 1; i <= n; i++) if (!deg[i]) { g[0].pb(i); deg[i] = 1; } 
	pos[0] = r + 1;
	int ans = r;
	while (l <= r) { 
		int mid = (l + r) >> 1;
		if (check(mid)) { ans = mid; r = mid - 1; } else l = mid + 1;
	} 
	printf("%d\n" , ans);
} 

