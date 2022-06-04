#include <bits/stdc++.h>
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll inf = 1e16;
const int maxn = 1e5;

pair<ll,int> tree[4 * maxn + 11];
ll ans[maxn + 11];
ll minn[4 * maxn + 11],lazy[4 * maxn + 11];
set<pair<ll,int> > t;

void push_up(int rt) { tree[rt] = min(tree[lson] , tree[rson]); }
void build(int rt,int l,int r) {
	if (l == r) { tree[rt] = make_pair(inf , l); return; }
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
	push_up(rt);
}
void update(int rt,int l,int r,int pos,ll val) {
	if (l > pos || r < pos) return;
	if (l == r) { tree[rt] = make_pair(val , l); return; }
	int mid = (l + r) >> 1;
	update(lson , l , mid , pos , val);
	update(rson , mid + 1 , r , pos , val);
	push_up(rt);
}
void Push_up(int rt) { minn[rt] = min(minn[lson] , minn[rson]); }

void push_down(int rt) { 
	if (minn[lson] < inf) { minn[lson] -= lazy[rt]; lazy[lson] += lazy[rt]; }
	if (minn[rson] < inf) { minn[rson] -= lazy[rt]; lazy[rson] += lazy[rt]; }
	lazy[rt] = 0;
	minn[lson] = max(minn[lson] , 0ll);
	minn[rson] = max(minn[rson] , 0ll);
} 

void update(int rt,int l,int r,int al,int ar,ll val) { 
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) {
		minn[rt] -= val; minn[rt] = max(minn[rt] , 0ll);
		lazy[rt] += val;
		return;
	}
	int mid = (l + r) >> 1;
	if (lazy[rt]) push_down(rt);
	update(lson , l , mid , al , ar , val);
	update(rson , mid + 1 , r , al , ar , val);
	Push_up(rt);
}

pair<ll,int> query(int rt,int l,int r,int al,int ar) {
	if (l > ar || r < al) return make_pair(inf , maxn + 1);
	if (l >= al && r <= ar) return tree[rt];
	int mid = (l + r) >> 1;
	return min(query(lson , l , mid , al , ar) , query(rson , mid + 1 , r , al , ar));
}

pair <ll,int> query(int rt,int l,int r) {
	int mid = (l + r) >> 1;
	if (l == r) return make_pair(minn[rt] , l);
	if (lazy[rt]) push_down(rt);
	if (minn[lson] <= minn[rson]) return query(lson , l , mid);
	return query(rson , mid + 1 , r);
} 

void upd(int rt,int l,int r,int pos,ll val) {
	if (l > pos || r < pos) return;
	if (l == r) { minn[rt] = val; return; }
	int mid = (l + r) >> 1;
	if (lazy[rt]) push_down(rt);
	upd(lson , l , mid , pos , val);
	upd(rson , mid + 1 , r , pos , val);
	Push_up(rt);
} 

int main(){ 
	int n; ll p;
	cin >> n >> p;
	build(1 , 1 , n);
	for (int i = 1; i <= 4 * n; i++) minn[i] = inf , lazy[i] = 0;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		update(1 , 1 , n , i , x);
		upd(1 , 1 , n , i , x);
	} 
	int out = 0;
	queue <int> q;
	set <int> s;
	ll Pas = 0;
	ll res = p;
	while (out < n) { 
		if (q.empty()) {
			pair <ll,int> pi = query(1 , 1 , n);
			Pas += pi.first;
			update(1 , 1 , n , 1 , n , pi.first);
			s.insert(pi.second);
			q.push(pi.second);
			upd(1 , 1 , n , pi.second , inf);
		} 
		else { 
			int lef = *s.begin();
			if (lef == 1) { 
				Pas += p;
				res = p;
				update(1 , 1 , n , 1 , n , p);
				ans[q.front()] = Pas;
				update(1 , 1 , n , q.front() , inf);
				s.erase(q.front());
				q.pop();
				out++;
			}
			else {
				pair<ll,int> pi = query(1 , 1 , n , 1 , lef - 1);
				if (Pas + res > pi.first) {
					res -= pi.first - Pas;
					q.push(pi.second);
					upd(1 , 1 , n , pi.second , inf);
					s.insert(pi.second);
				}
				else {
					Pas += p;
					res = p;
					update(1 , 1 , n , 1 , n , p);
					ans[q.front()] = Pas;
					update(1 , 1 , n , q.front() , inf);
					s.erase(q.front());
					q.pop();
					out++;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
} 

