#include <bits/stdc++.h>
using namespace std;

set <int> edge[1111];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		edge[u].insert(v);
		edge[v].insert(u);
	}
	int res = n;
	while (1) {
		int u,v; u = v = 0;
		for (int i = 1; i <= n; i++) if (edge[i].size() == 1) u = i;
		for (int i = 1; i <= n; i++) if (edge[i].size() == 1 && i != u) v = i;
		cout << "? " << u << " " << v << endl;
		int lca;
		cin >> lca;
		if (lca == u || lca == v || res == 3) {
			cout << "! " << lca << endl;
			return 0;
		}
		res -= 2;
		edge[*edge[u].begin()].erase(u);
		edge[*edge[v].begin()].erase(v);
		edge[u].clear(); edge[v].clear();
	}
} 

