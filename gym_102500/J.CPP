#include <bits/stdc++.h>
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const int maxn = 5e5;
pair<int,int> s[maxn + 11];
int a[maxn + 11];
int n,c,r;

struct segment_tree{
	int mat[3][3];
	segment_tree operator * (const segment_tree & rh) {
		segment_tree ans;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++){
				ans.mat[i][j] = n + 1;
				for (int k = 0; k < 2; k++)
					ans.mat[i][j] = min(ans.mat[i][j] , mat[i][k] + rh.mat[k ^ 1][j]);
			}
		return ans;
	}
}tree[4 * maxn + 11];

void build(int rt,int l,int r){
	if (l == r) {
		if (a[l] > 0) {
			tree[rt].mat[1][1] = 0; tree[rt].mat[0][1] = tree[rt].mat[1][0] = 1;
			tree[rt].mat[0][0] = n + 1;
		}
		else if (a[l] == 0) {
			tree[rt].mat[0][1] = tree[rt].mat[1][0] = 1;
			tree[rt].mat[0][0] = tree[rt].mat[1][1] = n + 1;
		}
		else {
			tree[rt].mat[1][1] = n + 1; tree[rt].mat[0][0] = 0;
			tree[rt].mat[0][1] = tree[rt].mat[1][0] = 1;
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
	tree[rt] = tree[lson] * tree[rson];
} 

void update(int rt,int l,int r,int pos) {
	if (l > pos || r < pos) return;
	if (l == r) { tree[rt].mat[0][0] = tree[rt].mat[1][1] = 0; return; }
	int mid = (l + r) >> 1;
	update(lson , l , mid , pos);
	update(rson , mid + 1 , r , pos);
	tree[rt] = tree[lson] * tree[rson];
}

int query() {
	int mn = n + 1;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			mn = min(mn , tree[1].mat[i][j]);
	return mn;
}

int main(){
	scanf("%d %d %d",&n,&c,&r);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		a[i] = x;
		s[i] = {abs(x) + 1 , i};
	}
	build(1 , 1 , n);
	sort(s + 1 , s + 1 + n);
	ll ans = 1ll * query() * r;
	for (int i = 1; i <= n; i++) {
		update(1 , 1 , n , s[i].second);
		ans = min(ans , 1ll * s[i].first * c + 1ll * query() * r);
	}
	printf("%lld\n" , ans);
} 

