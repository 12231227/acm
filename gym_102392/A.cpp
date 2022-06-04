#include <bits/stdc++.h>
#define pb emplace_back
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const int maxn = 4e5;
vector <int> pos[maxn + 11];
int a[maxn + 11];
struct node{
	int l,r,ans;
}tree[4 * maxn + 11];
int sta = 0;
node merge(node A,node B,int l,int r,int mid) {
	node ret;
	bool flag = 1ll * (a[mid] - sta) * (a[mid + 1] - sta) < 0 ? true : false;
	if (A.l == mid - l + 1 && flag) {
		ret.l = A.l + B.l;
	}
	else ret.l = A.l;
	if (B.r == r - mid && flag) {
		ret.r = A.r + B.r;
	}
	else ret.r = B.r;
	if (flag)
		ret.ans = A.ans - A.r / 2 + B.ans - B.l / 2 + (A.r + B.l) / 2;
	else ret.ans = A.ans + B.ans;
	return ret;
} 

void build(int rt,int l,int r) {
	if (l == r) {
		if (a[l] == sta) tree[rt] = {0 , 0 , 0};
		else tree[rt] = {1 , 1 , 0};
		return ;
	}
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
	tree[rt] = merge(tree[lson] , tree[rson] , l , r , mid);
}

void update(int rt,int l,int r,int pos) {
	if (l > pos || r < pos) return;
	if (l == r) {
		if (a[l] == sta) tree[rt] = {0 , 0 , 0};
		else tree[rt] = {1 , 1 , 0};
		return;
	}
	int mid = (l + r) >> 1;
	update(lson , l , mid , pos);
	update(rson , mid + 1 , r , pos);
	tree[rt] = merge(tree[lson] , tree[rson] , l , r , mid);
}

node query(int rt,int l,int r,int al,int ar) {
	if (l >= al && r <= ar) {
		return tree[rt];
	}
	int mid = (l + r) >> 1;
	if (mid >= ar) return query(lson , l , mid , al , ar);
	if (al > mid) return query(rson , mid + 1 , r , al , ar);
	return merge(query(lson , l , mid , al , ar) , query(rson , mid + 1 , r , al , ar) , max(l , al) , min(r , ar) , mid);
} 

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}
	for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
	build(1 , 1 , 2 * n);
	for (int i = 1; i <= m; i++) {
		sta = i;
		for (auto p : pos[i]) {
			update(1 , 1 , 2 * n , p); update(1 , 1 , 2 * n , p + n);
		}
		for (auto p : pos[i - 1]) {
			update(1 , 1 , 2 * n , p); update(1 , 1 , 2 * n , p + n);
		}
		if (pos[i].empty()) {
			printf("-1 ");
			continue;
		}
		int l = pos[i][0]; int r = pos[i][0] + n;
		int ret = query(1 , 1 , 2 * n , l , r).ans;
		printf("%d " , ret + n - (int)pos[i].size());
	} 
} 

