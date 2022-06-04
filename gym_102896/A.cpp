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
int ls[maxn + 11],rs[maxn + 11];
int tot = 1;
int val[maxn + 11],siz[maxn + 11],cnt[maxn + 11];

void build(int x,int res) { 
	cnt[x] = siz[x] = res;
	if (res == 1) return;
	int l = (res - 1) / 2;
	int r = res - 1 - l;
	if (l > 0) { ls[x] = ++tot; build(ls[x] , l); }
	if (r > 0) { rs[x] = ++tot; build(rs[x] , r); }
} 

void insert(int x) { 
	siz[x]++; cnt[x]--;
	if (val[x] == 1) { val[x] = 2; return; } 
	if (cnt[ls[x]] > 0 && siz[ls[x]] < siz[rs[x]]) insert(ls[x]); else insert(rs[x]);
} 

int main(){ 
	//freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a,b; cin >> a >> b;
	int n = a + b;
	if (a == 0) { 
		int x = b + 1;
		while (x % 2 == 0) x /= 2;
		if (x != 1) { 
			printf("-1\n");
			return 0;
		} 
	} 
	build(1 , n);
	for (int i = 1; i <= n; i++) val[i] = 1;
	assert(tot == n);
 	for (int i = 1; i <= b; i++)
		insert(1);
	bool flag = true;
	for (int i = 1; i <= n; i++) if (abs(siz[ls[i]] - siz[rs[i]]) > 1) flag = false;
	if (!flag) printf("-1\n");
	else { 
		for (int i = 1; i <= n; i++) { 
			printf("%d %d %d\n" , val[i] , ls[i] , rs[i]);
		} 
	} 
	return 0;
} 

