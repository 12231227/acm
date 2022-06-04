#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
using namespace std;

const int maxn = 2e5;
const int inf = 2e9;

struct segment{
	int tree[4 * maxn + 11][2];
	void build(int rt,int l,int r) {
		tree[rt][0] = tree[rt][1] = inf;
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(lson , l , mid);
		build(rson , mid + 1 , r);
	}
	void push_up(int rt) {
		if (tree[lson][0] < tree[rson][0]) {
			tree[rt][0] = tree[lson][0];
			tree[rt][1] = min(tree[lson][1] , tree[rson][0]);
		}
		else {
			tree[rt][0] = tree[rson][0];
			tree[rt][1] = min(tree[rson][1] , tree[lson][0]);
		}
	}
	void update(int rt,int l,int r,int pos,int val) {
		if (l > pos || r < pos) return;
		if (l == r) {
			tree[rt][0] = val;
			return;
		}
		int mid = (l + r) >> 1;
		update(lson , l , mid , pos , val);
		update(rson , mid + 1 , r , pos , val);
		push_up(rt);
	}
	pair <int,int> query(int rt,int l,int r,int al,int ar) {
		if (l > ar || r < al) return make_pair(inf , inf);
		if (l >= al && r <= ar) return make_pair(tree[rt][0] , tree[rt][1]);
		int mid = (l + r) >> 1;
		pair <int,int> x = query(lson , l , mid , al , ar);
		pair <int,int> y = query(rson , mid + 1 , r , al , ar);
		if (x.first < y.first) return make_pair(x.first , min(x.second , y.first));
		return make_pair(y.first , min(y.second , x.first));
	}
}seg[10];

int main(){
	//freopen("in.txt","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i = 0; i <= 9; i++) seg[i].build(1 , 1 , n);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d",&a);
		int x = 0;
		int val = a;
		while (val) {
			if (val % 10 != 0) seg[x].update(1 , 1 , n , i , a);
			x++;
			val /= 10;
		}
	}
	for (int i = 1; i <= m; i++) {
		int op;
		scanf("%d",&op);
		if (op == 1) {
			int ind,a;
			scanf("%d %d",&ind,&a);
			int val = a;
			int x = 0;
			while (val) {
				if (val % 10 != 0) seg[x].update(1 , 1 , n , ind , a); else seg[x].update(1 , 1 , n , ind , inf);
				x++;
				val /= 10;
			}
			for ( ; x <= 9; x++) seg[x].update(1 , 1 , n , ind , inf);
		}
		else{
			int l,r;
			scanf("%d %d",&l,&r);
			int ans = inf;
			for (int i = 0; i <= 9; i++) {
				pair <int ,int> res = seg[i].query(1 , 1 , n , l , r);
				if (res.second == inf) continue;
				ans = min(ans , res.first + res.second);
			}
			if (ans == inf) printf("-1\n"); else printf("%d\n" , ans);
		}
	}
}
