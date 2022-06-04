#include <bits/stdc++.h>
#define pb push_back
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const int maxn = 1e5;
int tree[4 * maxn + 11],lazy[4 * maxn + 11];
int a[maxn + 11],sta[maxn + 11],r[maxn + 11];
vector <int> v[maxn + 11];

void push_up(int rt) { tree[rt] = min(tree[lson] , tree[rson]); }

void build(int rt,int l,int r) {
	if (l == r) { tree[rt] = sta[l]; return; }
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
	push_up(rt);
} 

void push_down(int rt) { 
	int val = lazy[rt]; lazy[rt] = 0;
	tree[lson] += val;
	tree[rson] += val;
	lazy[lson] += val;
	lazy[rson] += val;
} 

void update(int rt,int l,int r,int al,int ar,int val) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) {
		tree[rt] += val;
		lazy[rt] += val;
		return;
	}
	if (lazy[rt] != 0) push_down(rt);
	int mid = (l + r) >> 1;
	update(lson , l , mid , al , ar , val);
	update(rson , mid + 1 , r , al , ar , val);
	push_up(rt);
}

int main(){
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		if (a[i] < a[1]) cnt++;
	} 
	for (int i = 1; i <= m; i++) {
		scanf("%d",&r[i]);
		sta[i] = cnt - r[i];
		cnt -= r[i];
		for (int j = 0; j < r[i]; j++) {
			int x;
			scanf("%d",&x);
			if (x < a[1]) cnt++;
			v[i].pb(x);
		} 
	} 
	build(1 , 1 , m);
	while (q--) { 
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if (x == m) {}
		else if (v[x][y - 1] > a[1] && a[1] > z) {
			update(1 , 1 , m , x + 1 , m , 1);
		} 
		else if (v[x][y - 1] < a[1] && a[1] < z) { 
			update(1 , 1 , m , x + 1 , m , -1);
		} 
		v[x][y - 1] = z;
		if (tree[1] >= 0) printf("1\n"); else printf("0\n");
	} 
} 

