#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const int maxn = 1e5;

int tree[4 * maxn + 11],lazy[4 * maxn + 11];

void push_up(int rt) { tree[rt] = max(tree[lson] , tree[rson]); }
void push_down(int rt) {
	int val = lazy[rt]; lazy[rt] = 0;
	tree[lson] += val; lazy[lson] += val;
	tree[rson] += val; lazy[rson] += val;
}

void update(int rt,int l,int r,int al,int ar,int val) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) { tree[rt] += val; lazy[rt] += val; return; }
	int mid = (l + r) >> 1;
	push_down(rt);
	update(lson , l , mid , al , ar , val);
	update(rson , mid + 1 , r , al , ar , val);
	push_up(rt);
}

int query(int rt,int l,int r,int al,int ar) {
	if (l > ar || r < al) return 0;
	if (l >= al && r <= ar) return tree[rt];
	push_down(rt);
	int mid = (l + r) >> 1;
	return max(query(lson , l , mid , al , ar) , query(rson , mid + 1 , r , al , ar));
}

int main(){
	int t;
	for (scanf("%d",&t);t;t--) {
		int n,k;
		scanf("%d %d",&n,&k);
		bool flag = false;
		int pos = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d",&x);
			if (x == k) pos = k;
			if (x >= k) update(1 , 1 , n , 1 , i , 1);
			else update(1 , 1 , n , 1 , i , -1);
			if (i > 1 && query(1 , 1 , n , 1 , i - 1) > 0) flag = true;
			if (n == 1 && x == k) flag = true;
		}
		if (flag && pos) puts("yes"); else puts("no");
		for (int i = 1; i <= 4 * n; i++) tree[i] = lazy[i] = 0;
	}
} 
