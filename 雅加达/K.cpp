#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
#define ll long long
using namespace std;

const ll mol = 1e9 + 7;
const int maxn = 100000;

int lazy[4 * maxn + 11];
char ch[maxn + 11];
struct matrix{
	ll a[2][2];
	matrix operator * (const matrix &rh) {
		matrix ans;
		for (int i = 0; i < 2; i++) 
			for (int j = 0; j < 2; j++) {
				ans.a[i][j] = 0;
				for (int k = 0; k < 2; k++)
					ans.a[i][j] = (ans.a[i][j] + a[i][k] * rh.a[k][j] % mol) % mol;
			}
		return ans;
	}
	matrix trans() {
		matrix ans;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++) ans.a[i][j] = a[i][j];
		swap(ans.a[0][1] , ans.a[1][0]);
		return ans;
	}
}lef[maxn * 4 + 11] , rig[maxn * 4 + 11];

matrix A = {1 , 1 , 0 , 1};
matrix B = {1 , 0 , 1 , 1};
matrix per = {1 , 0 , 0 , 1};

void push_up(int rt) {
	lef[rt] = lef[lson] * lef[rson];
	rig[rt] = rig[rson] * rig[lson];
}

void build(int rt,int l,int r) { 
	if (l == r) { 
		if (ch[l] == 'A') lef[rt] = A; else lef[rt] = B;
		rig[rt] = lef[rt];
		return;
	}
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
	push_up(rt);
} 

void upd(int rt) {
	lazy[rt] ^= 1;
	matrix tmpr = rig[rt].trans();
	matrix tmpl = lef[rt].trans();
	lef[rt] = tmpr;
	rig[rt] = tmpl;
}

void push_down(int rt) {
	upd(lson);
	upd(rson);
	lazy[rt] = 0;
}

void update(int rt,int l,int r,int al,int ar) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) { upd(rt); return; }
	if (lazy[rt]) push_down(rt);
	int mid = (l + r) >> 1;
	update(lson , l , mid , al , ar);
	update(rson , mid + 1 , r , al , ar);
	push_up(rt);
}

matrix query(int rt,int l,int r,int al,int ar) {
	if (l > ar || r < al) return per;
	if (l >= al && r <= ar) return rig[rt];
	if (lazy[rt]) push_down(rt);
	int mid = (l + r) >> 1;
	return query(rson , mid + 1 , r , al , ar) * query(lson , l , mid , al , ar);
}

int main(){ 
	int n,q;
	scanf("%d %d",&n,&q);
	scanf("%s",ch + 1);
	build(1 , 1 , n);
	while (q--) {
		int op;
		scanf("%d",&op);
		if (op == 1) { 
			int l,r;
			scanf("%d %d",&l,&r);
			update(1 , 1 , n , l , r);
		} 
		else { 
			int l,r; ll a,b;
			scanf("%d %d %lld %lld",&l,&r,&a,&b);
			matrix ans = query(1 , 1 , n , l , r);
			ll x = (ans.a[0][0] * a % mol + ans.a[0][1] * b % mol) % mol;
			ll y = (ans.a[1][0] * a % mol + ans.a[1][1] * b % mol) % mol;
			printf("%lld %lld\n" , x , y);
		}
	}
} 

