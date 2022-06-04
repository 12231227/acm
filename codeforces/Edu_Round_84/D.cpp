#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

const int maxn = 2e5;
int cnt;
int pos[maxn + 11],p[maxn + 11],c[maxn + 11];
bool vis[maxn + 11];
vector <int> d[maxn + 11];

void dfs(int x) {
	pos[++cnt] = c[x];
	vis[x] = true;
	if (!vis[p[x]]) dfs(p[x]);
}

int calc(int x,int y) {
	if (pos[x] < pos[y]) return pos[y] - pos[x];
	return cnt - pos[x] + pos[y];
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	for (int i = 3;i <= maxn; i++){
		d[i].pb(1);
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				d[i].pb(j);
				if (j * j < i) d[i].pb(i / j);
			}
		}
		sort(d[i].begin() , d[i].end());
	}
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) vis[i] = false;
		for (int i = 1; i <= n; i++) cin >> p[i];
		for (int i = 1; i <= n; i++) cin >> c[i];
		int ans = n;
		for (int i = 1; i <= n; i++)
			if (!vis[i]){
				cnt = 0;
				dfs(i); ans = min(ans , cnt);
				if (cnt == 1) continue;
				else if (cnt == 2) {
					if (pos[1] == pos[2]) ans = 1;
				}
				else {
					for (auto u : d[cnt]) {
						if (u >= ans) break;
						for (int j = 1; j <= u; j++){
							bool flag = true; int C = pos[j];
							for (int k = j;  ; k += u){
								if (k > cnt) break;
								if (pos[k] != C) { flag = false; break; }
							}
							if (flag) { ans = u; break; }
						}
					}
				}
			}
		cout << ans << endl;
	} 
} 

