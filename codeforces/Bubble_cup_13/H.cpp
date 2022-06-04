#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 5e5;
int L[maxn + 11],R[maxn + 11];
vector <pii> tree[4 * maxn + 11];
vector <int> rec[4 * maxn + 11];;
int ans[maxn + 11],que[maxn + 11];

struct node{
	int x,y,st,day;
};
vector <node> upd;

struct dsu{ 
	int fa[maxn + 11],rk[maxn + 11],con[maxn + 11];
	stack <pair<int* , int> > stk;
	void pre(int n) { for (int i = 1; i <= n; i++) fa[i] = i , rk[i] = con[i] = 1; }
	int get(int x) { while (x ^ fa[x]) x = fa[x]; return x; }
	int merge(int x,int y) {
		int fax = get(x) , fay = get(y);
		if (fax == fay) return 0;
		if (rk[fax] <= rk[fay]) { 
			stk.push({fa + fax , fa[fax]});
			fa[fax] = fay;
			stk.push({con + fay , con[fay]});
			con[fay] += con[fax];
			if (rk[fax] == rk[fay]) {
				stk.push({rk + fay , rk[fay]});
				rk[fay]++;
				return 3;
			}
			return 2;
		} 
		else { 
			stk.push({fa + fay , fa[fay]});
			fa[fay] = fax;
			stk.push({con + fax , con[fax]});
			con[fax] += con[fay];
			return 2;
		} 
	} 
	void revoke(int cnt) { while (cnt--) { *stk.top().first = stk.top().second; stk.pop(); } }
	int Con(int x) { return con[get(x)]; }
}D;

void update(int rt,int l,int r,int al,int ar,pii pi) {
	if (al > ar || l > ar || r < al) return;
	if (l >= al && r <= ar) { 
		tree[rt].pb(pi);
		return;
	} 
	int mid = (l + r) >> 1;
	update(lson , l , mid , al , ar , pi);
	update(rson , mid + 1 , r , al , ar , pi);
} 

void revoke(int rt) { for (int i = tree[rt].size() - 1; i >= 0; i--) D.revoke(rec[rt][i]); } 

void dfs(int rt,int l,int r) { 
	for (int i = 0; i < tree[rt].size(); i++)
		rec[rt].pb(D.merge(tree[rt][i].first , tree[rt][i].second));
	if (l == r) { 
		if (que[l]) ans[l] = D.Con(que[l]);
		revoke(rt);
		return;
	} 
	int mid = (l + r) >> 1;
	dfs(lson , l , mid);
	dfs(rson , mid + 1 , r);
	revoke(rt);
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,q,k; cin >> n >> q >> k;
	int day = 1; L[1] = 1;
	for (int i = 1; i <= q; i++) {
		int op,x,y;
		cin >> op;
		if (op == 1) {
			cin >> x >> y;
			upd.pb(node{x , y , i , day});
		}
		else if (op == 2) { cin >> x; que[i] = x; } 
		else {
			R[day] = i - 1; L[++day] = i;
		} 
	} 
	R[day] = q;
	D.pre(n);
	for (auto pi : upd){
		int Day = min(pi.day + k - 1 , day);
		update(1 , 1 , q , pi.st , R[Day] , make_pair(pi.x , pi.y));
	}	
	dfs(1 , 1 , q);
	for (int i = 1; i <= q; i++)
		if (que[i]) printf("%d\n" , ans[i]);
} 

