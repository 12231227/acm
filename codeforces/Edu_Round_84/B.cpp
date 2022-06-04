#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

const int maxn = 1e5;
map <pair<int,int> ,int> mp;
vector <int> g[maxn + 11];
bool va[maxn + 11],vb[maxn + 11];
vector <int> ta,tb;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		mp.clear();
		for (int i = 1; i <= n; i++) va[i] = false,vb[i] = false;
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;
			g[i].resize(k);
			for (int j = 0; j < k;j++) {
				cin >> g[i][j];
				mp[make_pair(i , g[i][j])] = 1;
			}
		}
		ta.clear(); tb.clear();
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < g[i].size(); j++)
				if (!vb[g[i][j]]) {
					va[i] = true;
					vb[g[i][j]] = true;
					break;
				}
		}
		for (int i = 1; i <= n; i++) {
			if (!va[i]) ta.pb(i);
			if (!vb[i]) tb.pb(i);
		}
		if (ta.size() == 0) {
			cout << "OPTIMAL" << endl;
			continue;
		}
		bool flag = false;
		for (auto i : ta) {
			if (flag) break;
			for (auto j : tb) {
				if (!mp.count(make_pair(i , j))) {
					flag = true;
					cout << "IMPROVE" << endl;
					cout << i << " " << j << endl;
					break;
				}
			}
		}
		if (!flag) cout << "OPTIMAL" << endl;
	}
}
