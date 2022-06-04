#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5;

ll ans;
int root,minn,all;
bool vis[maxn + 11] = {false};
vector <pair<ll,ll> > v;
vector <ll> s;
int a[maxn + 11],siz[maxn + 11],f[maxn + 11];
int bit[maxn + 11];
vector <int> edge[maxn + 11];

int lowbit(int x) { return x & (-x); }
int query(int x) { int ans = 0; for (; x; x -= lowbit(x)) ans += bit[x]; return ans; }
void update(int x,int val,int n) { for (; x <= n; x += lowbit(x)) bit[x] += val; }

void dfs(int x,int fa) {
	siz[x] = 1; f[x] = 0;
	for (auto v : edge[x]) {
		if (v == fa || vis[v]) continue;
		dfs(v , x);
		siz[x] += siz[v];
		f[x] = max(f[x] , siz[v]);
	}
	f[x] = max(f[x] , all - siz[x]);
	if (f[x] < minn) { minn = f[x]; root = x; }
}

void find(int x,int fa,ll sum,int mx) {
	v.push_back({max(mx , a[x]) , sum + a[x]});
	for (auto v : edge[x]) {
		if (v == fa || vis[v]) continue;
		find(v , x , sum + a[x] , max(mx , a[x]));
	}
}

ll calc(int x,ll val) {
	find(x , 0 , val , val);
	sort(v.begin() , v.end());
	ll cnt = 0;
	ll add = val ? val : a[x];
	for (auto pi : v) s.push_back(pi.second);
	sort(s.begin() , s.end());
	s.erase(unique(s.begin() , s.end()) , s.end());
	for (int i = 0; i < v.size(); i++) {
		pair <ll,ll> pi = v[i];
		int pos = upper_bound(s.begin() , s.end() , 2 * pi.first + add - pi.second) - s.begin();
		cnt += i - query(pos);
		pos = lower_bound(s.begin() , s.end() , pi.second) - s.begin() + 1;
		update(pos , 1 , s.size());
	}
	for (auto pi : v) {
		int pos = lower_bound(s.begin() , s.end() , pi.second) - s.begin() + 1;
		update(pos , -1 , s.size());
	}
	return cnt;
}

void solve(int x) {
	vis[x] = true;
	ans += calc(x , 0); v.clear(); s.clear();
	for (auto V : edge[x]) {
		if (vis[V]) continue;
		ans -= calc(V , a[x]); v.clear(); s.clear();
	}
	for (auto v : edge[x]) {
		if (vis[v]) continue;
		minn = all = siz[v]; root = 0;
		dfs(v , x);
		solve(root);
	}
}

int main(){
	int t;
	scanf("%d" , &t);
	while (t--) {
		int n;
		scanf("%d" , &n);
		for (int i = 1; i <= n; i++) scanf("%d" , &a[i]);
		for (int i = 1; i < n; i++) {
			int u,v;
			scanf("%d %d" , &u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		root = 0; minn = all = n; ans = 0;
		dfs(1 , 0);
		solve(root);
		printf("%lld\n" , ans);
		for (int i = 1; i <= n; i++) siz[i] = f[i] = 0,vis[i] = false,edge[i].clear();
	}
} 

