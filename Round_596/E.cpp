#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

const ll mol = 1e9 + 7;
const int maxn = 2000;

bool vis[maxn + 11][maxn + 11] = {false};
ll f[maxn + 11][maxn + 11][3];
int row[maxn + 11][maxn + 11],cul[maxn + 11][maxn + 11];
pair<int,int> ind[maxn + 11][maxn + 11];

struct BIT{ 
	int bit[maxn + 11];
	int n;
	int lowbit(int x) { return x & (-x); }
	void update(int x,int val) { for (; x <= n; x += lowbit(x)) bit[x] = (bit[x] + val) % mol; }
	int find(int x) { 
		if (x <= 0) return 0;
		int ans = 0;
		for (; x ; x -= lowbit(x)) ans = (ans + bit[x]) % mol;
		return ans;
	} 
	int query(int l,int r) { 
		if (l > r) return 0;
		return (find(r) - find(l - 1) + mol) % mol;
	} 
}r[maxn + 11],c[maxn + 11];

signed main(){
	int n,m;
	scanf("%lld %lld",&n,&m);
	for (int i = 1; i <= m; i++) r[i].n = n;
	for (int i = 1; i <= n; i++) c[i].n = m;
	char ch[maxn + 11];
	for (int i = 1; i <= n; i++) { 
		scanf("%s", ch + 1);
		for (int j = 1; j <= m; j++) vis[i][j] = (ch[j] == '.');
	} 
	if (n == 1 && m == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			row[i][j] = row[i][j + 1] + (vis[i][j] == false);
	for (int i = 1; i <= m; i++)
		for (int j = n; j >= 1; j--)
			cul[i][j] = cul[i][j + 1] + (vis[j][i] == false);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ind[i][j].first = m + 1 , ind[i][j].second = n + 1;
	for (int i = 1; i <= n; i++){ 
		int k = 2;
		for (int j = 2; j <= m; j++) {
			while (row[i][k] > m - j) k++;
			if (k <= j) ind[i][j].first = k - 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		int k = 2;
		for (int j = 2; j <= n; j++) {
			while (cul[i][k] > n - j) k++;
			if (k <= j) ind[j][i].second = k - 1;
		} 
	} 
	//0 - r 1 - c
	r[1].update(1 , 1);
	c[1].update(1 , 1);
	f[1][1][0] = f[1][1][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) continue;
			if (i == 1) {
				if (row[1][1] <= m - j) { f[i][j][0] = 1; r[j].update(1 , 1); }
			}
			else if (j == 1) {
				if (cul[1][1] <= n - i) { f[i][j][1] = 1; c[i].update(1 , 1); }
			} 
			else { 
				int addc = c[i].query(ind[i][j].first , j - 1);
				int addr = r[j].query(ind[i][j].second , i - 1);
				f[i][j][0] = (f[i][j][0] + addc) % mol;
				f[i][j][1] = (f[i][j][1] + addr) % mol;
				c[i].update(j , addr);
				r[j].update(i , addc);
			} 
		} 
	printf("%lld\n" , (f[n][m][0] + f[n][m][1]) % mol);
} 

