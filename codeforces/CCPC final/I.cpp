#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define lson rt << 1
#define rson rt << 1 | 1
#define ll long long
using namespace std;

const int maxn = 1e5;

vector <int> x,y,hor[maxn + 11];
int a[maxn + 11],b[maxn + 11];
int num[maxn + 11],cnt[maxn + 11];

struct node{
	int maxx,cnt;
}tree[4 * maxn + 11];

void push_up(int rt) { 
	if (tree[lson].maxx == tree[rson].maxx) { tree[rt].maxx = tree[rson].maxx; tree[rt].cnt = tree[lson].cnt + tree[rson].cnt; }
	else if (tree[lson].maxx > tree[rson].maxx) { tree[rt].maxx = tree[lson].maxx; tree[rt].cnt = tree[lson].cnt; }
	else { tree[rt].maxx = tree[rson].maxx; tree[rt].cnt = tree[rson].cnt; }
}

void build(int rt,int l,int r) {
	if (l == r) { tree[rt].maxx = cnt[l]; tree[rt].cnt = 1; return; }
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
	push_up(rt);
}

void change(int rt,int l,int r,int pos,int val) {
	if (l > pos || r < pos) return;
	if (l == r) { tree[rt].maxx = val; tree[rt].cnt = 1; return; }
	int mid = (l + r) >> 1;
	change(lson , l , mid , pos , val);
	change(rson , mid + 1 , r , pos ,val);
	push_up(rt);
}
int main(){
	//freopen("in.txt","r",stdin);
	int t;
	scanf("%d" , &t);
	int c = 0;
	while (t--) {
		c++;
		int n;
		scanf("%d" , &n);
		x.clear(); y.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d %d",&a[i],&b[i]);
			x.push_back(a[i]); y.push_back(b[i]);
		}
		memset(cnt,0,sizeof(cnt));
		memset(num,0,sizeof(num));
		sort(all(x)); sort(all(y));
		x.erase(unique(all(x)) , x.end());
		y.erase(unique(all(y)) , y.end());
		for (int i = 1; i <= n; i++) {
			int indx = lower_bound(all(x) , a[i]) - x.begin() + 1;
			int indy = lower_bound(all(y) , b[i]) - y.begin() + 1;
			hor[indy].push_back(indx);
			cnt[indx]++;
			num[indy]++;
			//mp[indx][indy] = 1;
		}
		//for (int i = 1; i <= x.size(); i++) cout << cnt[i] << " ";
		build(1 , 1 , x.size());
		int ans = 0;
		ll ansnum = 0;
		for (int i = 1; i <= y.size(); i++) { 
			for (auto u : hor[i]) { 
				change(1 , 1 , x.size() , u , cnt[u] - 1);
			}
			if (tree[1].maxx + num[i] > ans) { ans = tree[1].maxx + num[i]; ansnum = tree[1].cnt; } 
				else if (tree[1].maxx + num[i] == ans) ansnum += tree[1].cnt;
			for (auto u : hor[i]) change(1 , 1 , x.size() , u , cnt[u]);
			//cout << tree[1].cnt << endl;
			//printf("%d %d\n",ans, ansnum);
		}
		for (int i = 1; i <= y.size(); i++) hor[i].clear();
		printf("Case %d: %d %lld\n", c , ans, ans == 2 ? ansnum / 2 : ansnum);
	} 
	//cout << 1 << endl;
} 
