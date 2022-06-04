#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;
 
const int inf = 2e9;
const int maxn = 1e6;
 
struct Query{
	int l,h,id;
};
 
vector <pair <int,int> > que[4 * maxn + 11];
int ans[maxn + 11];
pair <int,int> ins[maxn + 11] = make_pair(0 , 0);
vector <int> v;
vector <Query> query[maxn + 11];
 
void update(int rt,int l,int r,int h,int pos,int time) {
	if (l > h || r < h) return;
	while (!que[rt].empty() && que[rt].back().second > time) que[rt].pop_back(); que[rt].push_back({pos , time});
	if (l == r) return;
	int mid = (l + r) >> 1;
	update(lson , l , mid , h , pos , time);
	update(rson , mid + 1 , r , h , pos , time);
}
 
int find_min(int rt,int l,int r,int pos,int time) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (que[rson].empty() || que[rson].back().first < pos) return find_min(lson , l , mid , pos , time);
	int ind = lower_bound(all(que[rson]) , make_pair(pos , -1)) - que[rson].begin();
	if (que[rson][ind].second < time) return find_min(rson , mid + 1 , r , pos , time);
	return find_min(lson , l , mid , pos , time);
}
 
int query_min(int rt,int l,int r,int al,int ar,int pos,int time) {
	if (l > ar || r < al || que[rt].empty()) return 0;
	if (l >= al && r <= ar) {
		if (que[rt].back().first < pos) return 0;
		int ind = lower_bound(all(que[rt]) , make_pair(pos , -1)) - que[rt].begin();
		if (que[rt][ind].second > time) return 0;
		return find_min(rt , l , r , pos , time);
	}
	int mid = (l + r) >> 1;
	int ret = query_min(rson , mid + 1 , r , al , ar , pos , time);
	if (!ret) return query_min(lson , l , mid , al , ar , pos , time);
	return ret;
}
 
int find_max(int rt,int l,int r,int pos,int time) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (que[lson].empty() || que[lson].back().first < pos) return find_max(rson , mid + 1 , r , pos , time);
	int ind = lower_bound(all(que[lson]) , make_pair(pos , -1)) - que[lson].begin();
	if (que[lson][ind].second < time) return find_max(lson , l , mid , pos , time);
	return find_max(rson , mid + 1 , r , pos , time);
}
 
int query_max(int rt,int l,int r,int al,int ar,int pos,int time) {
	if (l > ar || r < al || que[rt].empty()) return inf;
	if (l >= al && r <= ar) {
		if (que[rt].back().first < pos) return inf;
		int ind = lower_bound(all(que[rt]) , make_pair(pos , -1)) - que[rt].begin();
		if (que[rt][ind].second > time) return inf;
		return find_max(rt , l , r , pos , time);
	}
	int mid = (l + r) >> 1;
	int ret = query_max(lson , l , mid , al , ar , pos , time);
	if (ret == inf) return query_max(rson , mid + 1 , r , al , ar , pos , time);
	return ret;
}
 
int main(){
	int t;
	scanf("%d" , &t);
	while (t--) {
		int n,m;
		scanf("%d %d",&n,&m);
		int o = m;
		for (int i = 1; i <= m; i++) {
			ans[i] = -1;
			int op;
			scanf("%d" , &op);
			if (op == 0) {
				int x,h;
				scanf("%d %d",&x,&h);
				ins[x] = {h , i};
				v.push_back(h);
			}
			else {
				int l,r,h;
				scanf("%d %d %d",&l,&r,&h);
				query[r].push_back({l , h , i});
				v.push_back(h);
			}
		}
		sort(all(v)); v.erase(unique(all(v)) , v.end());
		m = v.size();
		for (int i = 1; i <= n; i++) {
			if (ins[i].first) {
				int H = lower_bound(all(v) , ins[i].first) - v.begin() + 1;
				update(1 , 1 , m , H , i , ins[i].second);
			}
			for (auto pi : query[i]) {
				ans[pi.id] = inf;
				int H = lower_bound(all(v) , pi.h) - v.begin() + 1;
				if (H > 1) { 
					int l = query_min(1 , 1 , m , 1 , H - 1 , pi.l , pi.id);
					if (l != 0) ans[pi.id] = min(ans[pi.id] , pi.h - v[l - 1]);
				}
				int r = query_max(1 , 1 , m , H , m , pi.l , pi.id);
				if (r != inf) ans[pi.id] = min(ans[pi.id] , v[r - 1] - pi.h);
			}
		}
		for (int i = 1; i <= o; i++) {
			if (ans[i] == -1) continue;
			if (ans[i] == inf) printf("-1\n");
			else printf("%d\n" , ans[i]);
		}
		v.clear();
		for (int i = 1; i <= n; i++) query[i].clear(),ins[i] = make_pair(0 , 0);
		for (int i = 1; i <= 4 * m; i++) que[i].clear();
	}
} 

