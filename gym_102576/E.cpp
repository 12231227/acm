#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pb emplace_back
using namespace std;

const int maxn = 4e6;
int tree[4 * maxn + 11];

int tot = 0;
vector <int> cul,row;
struct node{
	int px,qx,ymx,ymn,num;
}que[maxn + 11];

struct N{
	int mx,l,r,num;
};

vector <N> out[maxn + 11];
vector <pair<int,int> > in[maxn + 11];
int x[maxn + 11],y[maxn + 11],c[maxn + 11],ans[maxn + 11];

void update(int rt,int l,int r,int pos,int val) {
	if (l > pos || r < pos) return;
	tree[rt] = max(tree[rt] , val);
	if (l == r) return;
	int mid = (l + r) >> 1;
	update(lson , l , mid , pos , val);
	update(rson , mid + 1 , r , pos , val);
}

int query(int rt,int l,int r,int al,int ar) {
	if (l > ar || r < al) return 0;
	if (l >= al && r <= ar) return tree[rt];
	int mid = (l + r) >> 1;
	return max(query(lson , l , mid , al , ar) , query(rson , mid + 1 , r , al , ar));
}

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d",&x[i],&y[i],&c[i]);
		row.pb(x[i]);
		cul.pb(y[i] - c[i]);
		cul.pb(y[i] + c[i]);
	}
	for (int i = 1; i <= q; i++) {
		int py,qy;
		scanf("%d %d %d %d %d %d",&que[i].px,&py,&que[i].qx,&qy,&que[i].ymn,&que[i].ymx);
		if (que[i].px > que[i].qx) swap(que[i].px , que[i].qx);
		row.pb(que[i].px); row.pb(que[i].qx);
		cul.pb(que[i].ymn); cul.pb(que[i].ymx);
		que[i].num = i;
	}
	sort(all(row)); row.erase(unique(all(row)) , row.end());
	sort(all(cul)); cul.erase(unique(all(cul)) , cul.end());
	for (int i = 1; i <= n; i++) {
		int p = lower_bound(all(row) , x[i]) - row.begin() + 1;
		int l = lower_bound(all(cul) , y[i] - c[i]) - cul.begin() + 1;
		int r = lower_bound(all(cul) , y[i] + c[i]) - cul.begin() + 1;
		in[l].pb(make_pair(p , r));
		
	}
	for (int i = 1; i <= q; i++) {
		que[i].px = lower_bound(all(row) , que[i].px) - row.begin() + 1;
		que[i].qx = lower_bound(all(row) , que[i].qx) - row.begin() + 1;
		que[i].ymn = lower_bound(all(cul) , que[i].ymn) - cul.begin() + 1;
		que[i].ymx = lower_bound(all(cul) , que[i].ymx) - cul.begin() + 1;
		out[que[i].ymn].pb(N{que[i].ymx , que[i].px , que[i].qx , que[i].num});
	}
	for (int i = 1; i <= cul.size(); i++) {
		for (auto pi : in[i]) update(1 , 1 , row.size() , pi.first , pi.second);
		for (auto pi : out[i]) ans[pi.num] = query(1 , 1 , row.size() , pi.l , pi.r) - pi.mx;
	}
	for (int i = 1; i <= q; i++)
		printf("%s\n" , ans[i] >= 0 ? "NO" : "YES");
} 
