#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const int maxn = 2e5;

struct node{
	int x,y,z;
	bool operator < (const node &rh) {
		if (x != rh.x) return x < rh.x;
		return y < rh.y;
	}
}mon[maxn + 11];
pair<int,int> w[maxn + 11],d[maxn + 11];
int val[maxn + 11];
vector <int> v;
int tree[4 * maxn + 11],lazy[4 * maxn + 11];

void push_up(int rt) { tree[rt] = max(tree[lson] , tree[rson]); }
void build(int rt,int l,int r) {
	if (l == r) { tree[rt] = -val[l]; return; }
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
	push_up(rt);
}
void push_down(int rt) {
	int val = lazy[rt]; lazy[rt] = 0;
	tree[lson] += val; tree[rson] += val;
	lazy[lson] += val; lazy[rson] += val;
}
void update(int rt,int l,int r,int al,int ar,int val) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) {
		tree[rt] += val;
		lazy[rt] += val;
		return;
	}
	int mid = (l + r) >> 1;
	if (lazy[rt]) push_down(rt);
	update(lson , l , mid , al , ar , val);
	update(rson , mid + 1 , r , al , ar , val);
	push_up(rt);
}

int main(){
	int n,m,p;
	scanf("%d %d %d" , &n , &m, &p);
	for (int i = 1; i <= n; i++) scanf("%d %d",&w[i].first,&w[i].second);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d",&d[i].first,&d[i].second);
		v.push_back(d[i].first);
	}
	for (int i = 1; i <= p; i++) scanf("%d %d %d",&mon[i].x,&mon[i].y,&mon[i].z);
	sort(w + 1 , w + 1 + n); sort(d + 1 , d + 1 + m); sort(mon + 1 , mon + 1 + p);
	sort(all(v)); v.erase(unique(all(v)) , v.end());
	for (int i = 1; i <= m; i++) {
		int ind = lower_bound(all(v) , d[i].first) - v.begin() + 1;
		val[ind] = val[ind] == 0 ? d[i].second : min(val[ind] , d[i].second);
	}
	m = v.size();
	build(1 , 1 , m);
	int ind = 1;
	int ans = -2e9;
	for (int i = 1; i <= n; i++) { 
		int ret = -w[i].second;
		int j = ind;
		while (j <= p && mon[j].x < w[i].first) {
			if (mon[j].y >= v[m - 1]) { j++; continue; }
			int l = upper_bound(all(v) , mon[j].y) - v.begin() + 1;
			update(1 , 1 , m , l , m , mon[j].z);
			j++;
		}
		ind = j;
		ret += tree[1];
		ans = max(ret , ans);
	}
	printf("%d\n" , ans);
}

