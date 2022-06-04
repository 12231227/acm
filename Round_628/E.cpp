#include <bits/stdc++.h>
#define pb emplace_back
#define pii pair<int,int>
using namespace std;

const int maxn = 1e6;
vector <int> v;
map <pii,int> mp;
vector<int> edge[maxn + 11];
int dis[maxn + 11],vis[maxn + 11];
set<int> s;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int flag = 3;
	s.insert(1);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.clear();
		for (int j = 2; j * j <= x; j++)
			if (x % j == 0) {
				int cnt = 0;
				while (x % j == 0) { x /= j; cnt++; }
				if (cnt % 2) v.pb(j);
			}
		if (x > 1) v.pb(x);
		if (v.empty()) flag = 1;
		else if (v.size() == 1) {
			if (mp.count({1 , v[0]})) flag = min(2 , flag);
			else { edge[1].pb(v[0]); edge[v[0]].pb(1); mp[{1 , v[0]}] = 1; }
		}
		else {
			if (mp.count({v[0] , v[1]})) flag = min(2 , flag);
			else { edge[v[0]].pb(v[1]); edge[v[1]].pb(v[0]); mp[{v[0] , v[1]}] = mp[{v[1] , v[0]}] = 1; }
		}
		for (auto d : v) s.insert(d);
	}
	if (flag < 3) { cout << flag << endl; return 0; }
	int ans = n + 1;
	for (auto d : s) {
		if (d > 1000) break;
		for (auto D : s) dis[D] = n + 1 , vis[D] = -1;
		dis[d] = vis[d] = 0;
		queue<int> q; q.push(d);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto e : edge[u]) {
				if (vis[e] != -1) {
					if (vis[u] != e)
						ans = min(dis[e] + dis[u] + 1 , ans);
					continue;
				}
				q.push(e); dis[e] = dis[u] + 1; vis[e] = u;
			}
		} 
	}
	if (ans == n + 1) cout << -1 << endl;
	else cout << ans << endl;
} 

