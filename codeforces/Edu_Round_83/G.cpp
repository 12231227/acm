#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const int inf = 1e9;
const int maxn = 1e6;
bool vis[maxn + 11];
int x[maxn + 11],f[maxn + 11],nxt[maxn + 11][26],id[maxn + 11];
int n;
int tot = 0;

void dfs(int x,int mn) {
	if (vis[x]) {
		id[x] = ++tot;
		f[x] = min(f[x] , mn + id[x]);
		mn = min(mn , f[x] - id[x] + 1);
	}
	else {
		id[x] = tot;
		mn = min(mn , f[x] - id[x]);
	}
	for (int i = 0; i < 26; i++)
		if (nxt[x][i]) {
			f[nxt[x][i]] = f[x] + 1;
			dfs(nxt[x][i] , mn);
		}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p; char c;
		cin >> p >> c;
		nxt[p][c - 'a'] = i;
	}
	int k; cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> x[i];
		vis[x[i]] = true;
	}
	dfs(0 , 0);
	for (int i = 1; i <= k; i++)
		cout << f[x[i]] << " ";
} 
