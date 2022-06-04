#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

vector <int> ans[200],edge[200];
int fa[21],sta[21];

void dfs(int x) {
	for (auto u : edge[x]) {
		dfs(u);
		vector <int> res = ans[x];
		for (auto v : ans[u]) {
			res.pb(v);
			if (sta[x] & 1) {
				for (int i = 0; i < ans[x].size(); i++) res.pb(ans[x][i]);
			}
			else {
				for (int i = ans[x].size() - 1; i >= 0; i--) res.pb(ans[x][i]);
			}
			sta[x] ^= 1;
		}
		res.swap(ans[x]);
	} 
	if (x != 1) { 
		reverse(all(ans[x]));
		ans[x].pb(x);
		reverse(all(ans[x]));
	} 
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) sta[i] = 1;
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		edge[x].pb(i);
	}
	dfs(1);
	printf("%d\n" , ans[1].size());
	for (auto u : ans[1]) printf("%d " , u);
} 
