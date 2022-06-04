#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const int maxn = 2e5;

int ans[maxn + 11],tree[4 * maxn + 11];
struct node{
	int l,r,lab,pos;
}row[maxn + 11];

struct cmp{ bool operator() (const node&a,const node &b) const { return a.r > b.r; } };

int query(int rt,int l,int r,int al,int ar) {
	if (l > ar || r < al) return 0;
	if (l >= al && r <= ar) return tree[rt];
	int mid = (l + r) >> 1;
	return max(query(lson , l , mid , al , ar) , query(rson , mid + 1 , r , al , ar));
}

void update(int rt,int l,int r,int pos,int val) {
	if (l > pos || r < pos) return;
	tree[rt] = max(tree[rt] , val);
	if (l == r) return;
	int mid = (l + r) >> 1;
	update(lson , l , mid , pos , val);
	update(rson , mid + 1 , r , pos , val);
} 

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d",&row[i].l,&row[i].r);
		row[i].pos = i;
	}
	sort(row + 1 , row + 1 + n , [&](node a,node b) { return a.l != b.l ? a.l < b.l : a.r < b.r; });
	int ind = 0;
	priority_queue <node , vector <node> , cmp> q;
	for (int i = 1; i <= n; i++) { 
		while (ind + 1 <= n && row[ind + 1].l == i) { ind++; q.push(row[ind]); }
		node t = q.top(); q.pop();
		ans[t.pos] = i;
	} 
	for (int i = 1; i <= n; i++) row[i].lab = ans[row[i].pos];
	sort(row + 1 , row + 1 + n , [&](node a,node b) { return a.lab < b.lab; });
	int a = -1 , b = -1;
	for (int i = 1; i <= n; i++) {
		int mx = query(1 , 1 , n , i , n);
		if (mx >= row[i].l) { a = row[i].pos; b = row[mx].pos; break; }
		update(1 , 1 , n , row[i].r , i);
	}
	if (a == -1 && b == -1) {
		puts("YES");
		for (int i = 1; i <= n; i++) printf("%d%s" , ans[i] , i == n ? "\n" : " ");
	}
	else {
		puts("NO");
		for (int i = 1; i <= n; i++) printf("%d%s" , ans[i] , i == n ? "\n" : " ");
		swap(ans[a] , ans[b]);
		for (int i = 1; i <= n; i++) printf("%d%s" , ans[i] , i == n ? "\n" : " ");
	}
} 

