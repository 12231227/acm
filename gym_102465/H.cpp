#include <bits/stdc++.h>
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
using namespace std;

const int maxn = 1e5;
bool vis[maxn + 11];
int a[maxn + 11];
vector <int> v;
int n,m;
vector <pii> edge[maxn + 11];
int bit[maxn + 11];

int lowbit(int x) { return x & (-x); }
void update(int x,int val) { for (; x <= m; x += lowbit(x)) bit[x] += val; }
int query(int x) { int ans = 0; for (; x ; x -= lowbit(x)) ans += bit[x]; return ans; }

void dij(int s,int dis[]) {
	for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f,vis[i] = false;
	dis[s] = 0;
	priority_queue<pii , vector<pii> , greater<pii> > q;
	q.push({0 , s});
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto pi : edge[u]) {
			int v = pi.first;
			if (vis[v]) continue;
			if (dis[v] > dis[u] + pi.second) { 
				dis[v] = dis[u] + pi.second;
				q.push({dis[v] , v});
			}
		}
	} 
} 

struct node{
	int x,y,z,num;
	bool vis;
	bool operator == (const node &rh) const {
		return x == rh.x && y == rh.y && z == rh.z;
	}
}s[maxn + 11],t[maxn + 11];

void cdq(int l,int r) {
	if (l >= r) return;
	int mid = (l + r) >> 1;
	int tot = l;
	cdq(l , mid); cdq(mid + 1 , r);
	int i,j;
	for (i = l,j = mid + 1;i <= mid && j <= r;) { 
		if (s[i].y <= s[j].y) {
			int ind = lower_bound(all(v) , s[i].z) - v.begin() + 1;
			update(ind , 1);
			t[tot++] = s[i++];
		}
		else {
			int ind = lower_bound(all(v) , s[j].z) - v.begin() + 1;
			int cnt = query(ind);
			if (cnt > 0) s[j].vis = true;
			t[tot++] = s[j++];
		}
	} 
	while (i <= mid) {
		int ind = lower_bound(all(v) , s[i].z) - v.begin() + 1;
		update(ind , 1);
		t[tot++] = s[i++];
	}
	while (j <= r) {
		int ind = lower_bound(all(v) , s[j].z) - v.begin() + 1;
		int cnt = query(ind);
		if (cnt > 0) s[j].vis = true;
		t[tot++] = s[j++];
	}
	for (int i = l; i <= mid; i++) {
		int ind = lower_bound(all(v) , s[i].z) - v.begin() + 1;
		update(ind , -1);
	}
	for (int i = l; i <= r; i++) s[i] = t[i];
} 

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w; u++; v++;
		edge[u].push_back({v , w});
		edge[v].push_back({u , w});
	}
	dij(1 , a); for (int i = 1; i <= n; i++) s[i].x = a[i];
	dij(2 , a); for (int i = 1; i <= n; i++) s[i].y = a[i];
	dij(3 , a); for (int i = 1; i <= n; i++) s[i].z = a[i];
	sort(s + 1 , s + 1 + n , [&](node a,node b) {
		if (a.x != b.x) return a.x < b.x;
		if (a.y != b.y) return a.y < b.y;
		return a.z < b.z;
	});
	int tot = 0; s[0].x = s[0].y = s[0].z = 0;
	for (int i = 1; i <= n; i++) {
		s[i].vis = false;
		if (s[i] == s[tot]) s[tot].num++;
		else { s[++tot] = s[i]; s[tot].num = 1; } 
		v.push_back(s[i].z);
	}
	sort(all(v));
	v.erase(unique(all(v)) , v.end());
	m = v.size();
	cdq(1 , tot);
	int ans = 0;
	for (int i = 1; i <= tot; i++)
		if (!s[i].vis) ans += s[i].num;
	cout << ans << endl;
} 
