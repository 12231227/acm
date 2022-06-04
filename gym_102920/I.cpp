#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const ll inf = -1e18;
const int maxn = 2000;
const int maxm = 2e5;

char BUF[1 << 22], *ST, *EN;
#define gc (ST == EN && (ST = BUF, EN = BUF + fread(BUF, 1, 1 << 21, stdin), ST == EN) ? EOF : *ST++)

template<class T> void read(T &x){
	int f=0; x=0; char ch=gc;
	for(;!isdigit(ch);ch=gc) f|=(ch=='-');
	for(;isdigit(ch);ch=gc) x=x*10+ch-'0';
	if(f) x=-x;
}

struct node{
	int st; ll val; int id;
};

ll a[maxn + 11],s[maxn + 11][maxn + 11],ans[maxm + 11];
vector <node> que[maxn + 11];
vector <ll> v;
int tree[4 * maxn * maxn + 11];

int query(int rt,int l,int r,int al,int ar,int pos) {
	if (l > ar || r < al) return -1;
	if (l == r) {
		if (tree[rt] >= pos) return l;
		return -1;
	}
	int mid = (l + r) >> 1;
	int ret = -1;
	if (tree[rson] >= pos) ret = query(rson , mid + 1 , r , al , ar , pos);
	if (ret == -1 && tree[lson] >= pos) return query(lson , l , mid , al , ar , pos);
	return ret;
} 

void push_up(int rt) { tree[rt] = max(tree[lson] , tree[rson]); }
void update(int rt,int l,int r,int pos,int val) {
	if (l == r) {
		tree[rt] = max(tree[rt] , val);
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= pos) update(lson , l , mid , pos , val);
	else update(rson , mid + 1 , r , pos , val);
	push_up(rt);
}

int main(){ 
	int n,m; read(n); read(m);
	for (int i = 1; i <= n; i++) {
		read(s[i][i]);
		v.pb(s[i][i]);
	}
	for (int i = 1; i <= m; i++) { 
		int s,e; ll u; read(s); read(e); read(u);
		que[e].pb(node{s , u , i});
	} 
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++){
			s[i][j] = s[i][j - 1] + s[j][j];
			v.pb(s[i][j]);
		} 
	sort(all(v)); v.erase(unique(all(v)) , v.end());
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int ind = lower_bound(all(v) , s[j][i]) - v.begin() + 1;
			update(1 , 1 , v.size() , ind , j);
		}
		for (auto pi : que[i]) { 
			ll mx = inf;
			int ind = upper_bound(all(v) , pi.val) - v.begin();
			if (ind) mx = query(1 , 1 , v.size() , 1 , ind , pi.st);
			if (mx == -1) mx = inf;
			if (mx != inf) mx = v[mx - 1];
			ans[pi.id] = mx;
		} 
	} 
	for (int i = 1; i <= m; i++)
		if (ans[i] != inf) printf("%lld\n" , ans[i]); else printf("NONE\n");

} 
