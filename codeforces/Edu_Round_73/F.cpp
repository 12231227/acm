#include <bits/stdc++.h>
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const ll inf = 1e16;
const int maxn = 1e6;

vector <int> ind;
vector <pair<int ,int> > hor[maxn + 11],ver[maxn + 11];
int a[maxn + 11],b[maxn + 11],c[maxn + 11];

struct segment{
	pair <ll,ll> maxx;
	ll lazy;
}tree[4 * maxn + 11];

void push_up(int rt) { tree[rt].maxx = max(tree[lson].maxx , tree[rson].maxx); }

void build(int rt,int l,int r) {
	if (l == r) { tree[rt].maxx = make_pair(ind[0] - ind[l - 1] , l);  return; }
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
	push_up(rt);
}

void push_down(int rt) {
	ll val = tree[rt].lazy; tree[rt].lazy = 0;
	tree[lson].maxx.first += val; tree[rson].maxx.first += val;
	tree[lson].lazy += val; tree[rson].lazy += val;
}

pair <ll,ll> query(int rt,int l,int r,int al,int ar) {
	if (l > ar || r < al) return make_pair(-inf , -inf);
	if (l >= al && r <= ar) return tree[rt].maxx;
	if (tree[rt].lazy) push_down(rt);
	int mid = (l + r) >> 1;
	return max(query(lson , l , mid , al , ar) , query(rson , mid + 1 , r , al , ar));
}

void update(int rt,int l,int r,int al,int ar,ll val) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) {
		tree[rt].maxx.first += val;
		tree[rt].lazy += val;
		return;
	}
	if (tree[rt].lazy) push_down(rt);
	int mid = (l + r) >> 1;
	update(lson , l , mid , al , ar , val);
	update(rson , mid + 1 , r , al , ar , val);
	push_up(rt);
}

int main(){
	//freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		ind.push_back(a[i]); ind.push_back(b[i]);
	}
	sort(ind.begin() , ind.end());
	ind.erase(unique(ind.begin() , ind.end()) , ind.end());
	for (int i = 1; i <= n; i++) {
		int x = lower_bound(ind.begin(),ind.end() , a[i]) - ind.begin() + 1;
		int y = lower_bound(ind.begin(),ind.end() , b[i]) - ind.begin() + 1;
		if (x <= y) ver[x].push_back(make_pair(y , c[i]));
		else hor[y].push_back(make_pair(x , c[i]));
	} 
	build(1 , 1 , ind.size());
	for (int i = 1; i <= ind.size(); i++) { 
		for (int j = 0; j < ver[i].size(); j++){ 
			update(1 , 1 , ind.size() , ver[i][j].first , ind.size() , ver[i][j].second);
		} 
		for (int j = 0; j < hor[i].size(); j++){ 
			update(1 , 1 , ind.size() , hor[i][j].first , ind.size() , hor[i][j].second);
		} 
	} 
	ll ans = 0;
	int x1,x2;
	x1 = x2 = 2e9;
	int indans;
	for (int i = 1; i <= ind.size(); i++) { 
		pair<ll , ll> res = query(1 , 1 , ind.size() , i , ind.size());
		if (res.first > ans) {
			ans = res.first;
			x1 = ind[i - 1];
			x2 = ind[res.second - 1];
		}
		if (i == ind.size()) continue;
		for (int j = 0; j < ver[i].size(); j++){ 
			update(1 , 1 , ind.size() , ver[i][j].first , ind.size() , -ver[i][j].second);
		} 
		for (int j = 0; j < hor[i].size(); j++){ 
			update(1 , 1 , ind.size() , hor[i][j].first , ind.size() , -hor[i][j].second);
		} 
		update(1 , 1 , ind.size() , i + 1 , ind.size() , ind[i] - ind[i - 1]);
	} 
	printf("%lld\n" , ans);
	printf("%d %d %d %d\n",x1,x1,x2,x2);
} 
