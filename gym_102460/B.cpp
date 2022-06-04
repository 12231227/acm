#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int f[maxn + 11][5];
vector <int> edge[maxn + 11];

void dfs(int x,int fa) {
	if (x != fa && edge[x].size() == 1) { 
		f[x][0] = 1; f[x][1] = maxn; f[x][2] = 0;
		return;
	} 
	for (auto v : edge[x]) {
		if (v == fa) continue;
		dfs(v , x);
	}
	int s0 = 0; int s1 = 0; int s2 = 0;
	int mn = maxn;
	int mn2 = maxn;
	pair <int,int> sub0[2],sub2[2];
	sub0[0] = sub0[1] = sub2[0] = sub2[1] = {maxn , maxn};
	int deg = 0;
	for (auto v : edge[x]) { 
		if (v == fa) continue; deg++;
		int t = min(f[v][0] , f[v][1]);
		s0 += min(t , f[v][2]);
		s1 += t;
		s2 += f[v][1];
		mn = min(mn , f[v][0] - t);
		mn2 = min(mn2 , f[v][2] - f[v][1]);
		if (f[v][0] - t < sub0[0].first) { sub0[1] = sub0[0]; sub0[0] = {f[v][0] - t , v}; } 
		else if (f[v][0] - t < sub0[1].first) sub0[1] = {f[v][0] - t , v};
		if (f[v][2] - t < sub2[0].first) { sub2[1] = sub2[0]; sub2[0] = {f[v][2] - t , v}; } 
		else if (f[v][2] - t < sub2[1].first) sub2[1] = {f[v][2] - t , v};
	} 
	f[x][0] = min(s0 + 1 , s1 + mn);
	if (deg == 1) f[x][1] = maxn;
	else if (sub0[0].second != sub2[0].second) f[x][1] = s1 + sub0[0].first + sub2[0].first;
	else {
		f[x][1] = s1 + min(sub0[0].first + sub2[1].first , sub0[1].first + sub2[0].first);
	}
	f[x][2] = s2 + min(mn2 , 0);
} 

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) { 
		int u,v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	} 
	dfs(1 , 1);
	cout << min(f[1][0] , f[1][1]) << endl;
} 

