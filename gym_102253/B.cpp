#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e5;
const int mol = 1e9 + 7;
int rk;
int p[maxn + 110];
int Rank[30],tag[30];
char ch[maxn + 11];
int a[30][maxn + 110];
vector <int> v[maxn + 11];

void Sort(int sta,int pos) {
	if (pos < 0) {
		for (int i = 0; i < 26; i++)
			if (sta & (1 << i)) {
				if (tag[i]) Rank[i] = --rk;
			}
		for (int i = 0; i < 26; i++)
			if (sta & (1 << i)) {
				if (!tag[i]) Rank[i] = --rk;
			}
		return;
	}
	vector <int> v[26];
	for (int i = 0; i < 26; i++) 
		if (sta & (1 << i)) {
			v[a[i][pos]].pb(i);
		}
	for (int i = 25; i >= 0; i--) {
		if (v[i].empty()) continue;
		if (v[i].size() == 1) { Rank[v[i][0]] = --rk; continue; }
		int s = 0;
		for (auto u : v[i]) s += (1 << u);
		Sort(s , pos - 1);
	}
} 

int main(){ 
	int n = 1e5 + 100;
	int c = 0;
	p[0] = 1;
	for (int i = 1; i <= n; i++) p[i] = 1ll * p[i - 1] * 26 % mol;
	while (~scanf("%d",&n)) {
		c++;
		for (int i = 0; i < 26; i++) tag[i] = 0;
		int len = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%s" , ch + 1);
			v[i].clear();
			int m = strlen(ch + 1);
			len = max(len , m);
			for (int j = m; j >= 1; j--) {
				int p = ch[j] - 'a';
				v[i].pb(p);
				a[p][m - j]++;
			}
			tag[ch[1] - 'a'] = 1;
		}
		for (int j = 0; j < 26; j++){
			for (int i = 0; i < len; i++)
				if (a[j][i] >= 26) {
					a[j][i + 1] += a[j][i] / 26;
					a[j][i] %= 26;
				}
			while (a[j][len]) {
				a[j][len + 1] += a[j][len] / 26;
				a[j][len] %= 26;
				len++;
			}
		}
		int sta = (1 << 26) - 1;
		rk = 26;
		Sort(sta , len - 1);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < v[i].size(); j++)
				ans = (ans + 1ll * p[j] * Rank[v[i][j]] % mol) % mol;
		printf("Case #%d: " , c);
		printf("%d\n" , ans);
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < len; j++) a[i][j] = 0;
	} 
} 
