#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int dx[] = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1};
const int dy[] = {1 , 0 , -1 , -1 , 1 , -1 , 0 , 1};
const int maxn = 1000;
int fa[maxn + 11],siz[maxn + 11],x1[maxn + 11],x2[maxn + 11],Y1[maxn + 11],y2[maxn + 11],sl[maxn + 11],sr[maxn + 11],cl[maxn + 11],cr[maxn + 11];
int flag[maxn + 11][maxn + 11];
int upd[maxn + 11][maxn + 11];
int vis[maxn + 11][maxn + 11],a[maxn + 11][maxn + 11];
int tag[maxn + 11];
vector <int> con[maxn + 11];

int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }

void merge(int x,int y) {
	int fax = get(x) , fay = get(y);
	if (fax == fay) return;
	fa[fay] = fax;
	siz[fax] += siz[fay];
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m,K; cin >> n >> m >> K;
	for (int i = 1; i <= K; i++)
		cin >> x1[i] >> Y1[i] >> x2[i] >> y2[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			assert(a[i][j] >= 0);
			assert(a[i][j] <= 100);
		}
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= 100; j++) cl[j] = cr[j] = sl[j] = sr[j] = 0;
		for (int j = x1[i]; j <= x2[i]; j++)
			for (int k = Y1[i]; k <= y2[i]; k++) {
				flag[j][k] = i;
				int x = a[j][k];
				cl[x]++; cr[x]++;
				sl[x] += x; sr[x] += x;
			}
		for (int j = 2; j <= 100; j++) cl[j] += cl[j - 1] , sl[j] += sl[j - 1];
		for (int j = 99; j >= 1; j--) cr[j] += cr[j + 1] , sr[j] += sr[j + 1];
		for (int j = 1; j <= 100; j++)
			upd[i][j] = j * cl[j - 1] - sl[j - 1] + sr[j + 1] - j * cr[j + 1];
	} 
	for (int i = 1; i <= K; i++) {
		for (int j = x1[i]; j <= x2[i]; j++)
			for (int k = Y1[i]; k <= y2[i]; k++) {
				for (int p = 0; p < 8; p++)
					if (j + dx[p] > 0 && j + dx[p] <= n && k + dy[p] > 0 && k + dy[p] <= m)
						if (flag[j + dx[p]][k + dy[p]]) vis[i][flag[j + dx[p]][k + dy[p]]] = 1;
			} 
	} 
	bool can = true;
	memset(tag , -1 , sizeof(tag));
	for (int i = 1; i <= K; i++) fa[i] = i , siz[i] = 1;
	for (int i = 1; i <= K; i++) {
		if (tag[i] == -1) tag[i] = 0;
		for (int j = 1; j <= K; j++)
			if (i != j && vis[i][j]) {
				merge(i , j);
				if (tag[i] == tag[j]) can = false; else tag[j] = tag[i] ^ 1;
			}
	}
	if (!can) { 
		cout << -1 << endl;
		return 0;
	} 
	for (int i = 1; i <= K; i++) con[get(i)].pb(i);
	int ret = 100 * 1000 * 1000;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)  { 
			int ans = 0;
			for (int k = 1; k <= K; k++) {
				if (con[k].empty()) continue;
				if (con[k].size() == 1) { 
					ans += min(upd[k][i] , upd[k][j]);
					continue; 
				} 
				int ans0 = 0 , ans1 = 0;
				for (auto u : con[k]) ans0 += tag[u] ? upd[u][i] : upd[u][j];
				for (auto u : con[k]) ans1 += tag[u] ? upd[u][j] : upd[u][i];
				ans += min(ans0 , ans1);
			}
			ret = min(ret , ans);
		}
	cout << ret << endl;
	return 0;
} 
