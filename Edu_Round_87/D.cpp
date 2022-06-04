#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const int maxn = 1e6;

int tree[4 * maxn + 11];

void update(int rt,int l,int r,int pos,int val) {
	if (l > pos || r < pos) return;
	tree[rt] += val;
	if (l == r) return;
	int mid = (l + r) >> 1;
	update(lson , l , mid , pos , val);
	update(rson , mid + 1 , r , pos , val);
}

int query(int rt,int l,int r,int k) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (tree[lson] >= k) return query(lson , l , mid , k);
	return query(rson , mid + 1 , r , k - tree[lson]);
}

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		update(1 , 1 , n , x , 1);
	}
	for (int i = 1; i <= q; i++) {
		int k;
		scanf("%d",&k);
		if (k > 0) update(1 , 1 , n , k , 1);
		else update(1 , 1 , n , query(1 , 1 , n , -k) , -1);
	}
	if (tree[1] == 0) puts("0");
	else printf("%d\n" , query(1 , 1 , n , 1));
} 
