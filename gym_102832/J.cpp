#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1500;
const int mol = 1e9 + 7;
int f[maxn + 11][maxn + 11];
int bit[maxn + 11],r[5 * maxn + 11],l[5 * maxn + 11],can[maxn + 11];

bool check(int l1,int r1,int l2,int r2) { if (l1 == l2 && r1 == r2) return false; return l1 >= r2 || l2 >= r1 || (l1 <= l2 && r1 >= r2) || (l2 <= l1 && r2 >= r1); }
int add(int a,int b) { a += b; if (a >= mol) a -= mol; return a; }

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,k; cin >> n >> k;
	for (int i = 1; i <= k; i++) { int c,o; cin >> c >> o; l[i] = c - o; r[i] = c + o; }
	for (int i = 1; i <= n; i++)
		for (int j = 1; 2 * j <= i && j <= 5; j++) {
			bool flag = true;
			for (int p = 1; p <= k; p++)
				if (!check(l[p] , r[p] , i - 2 * j , i)) { flag = false; break; }
			if (flag) can[i] |= (1 << (j - 1));
		}
	for (int i = 0; i < 32; i++) { 
		for (int j = 4; j >= 0; j--)
			if (i & (1 << j)) {
				bit[i] = (1 << (2 * (j + 1))) - 1;
				break;
			}
	} 
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) 
		for (int pre = 0; pre < 1024; pre++) {
			if (!f[i - 1][pre]) continue;
			int mask;
			if (pre & 512) mask = (pre ^ 512) << 1; else mask = (pre << 1);
			for (int j = 0; j < 32; j++) {
				if ((j & can[i]) != j) continue;
				bool flag = true;
				for (int p = 0; p < 5; p++)
					if (j & (1 << p)){
						int la = (pre << 1);
						if (la & (1 << (2 * p + 1))) {
							flag = false; break;
						}
					} 
				if (flag) { 
					f[i][(mask | ((bit[j] >> 1)))] = add(f[i][(mask | ((bit[j] >> 1)))] , f[i - 1][pre]);
				} 
			}
		}
	int ans = 0;
	for (int i = 0; i < 1024; i++) ans = add(ans , f[n][i]);
	cout << ans << endl;
} 
