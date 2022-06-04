#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const int maxn = 2e5;

int n,m;
int h[maxn + 11];
int maxx[4 * maxn + 11];

void push_up(int rt) { maxx[rt] = max(maxx[lson] , maxx[rson]); }

void build(int rt,int l,int r) {
	if (l == r) {
		maxx[rt] = h[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lson , l , mid);
	build(rson , mid + 1 , r);
	push_up(rt);
} 

void update(int rt,int l,int r,int pos,int val) {
	if (l > pos || r < pos) return;
	if (l == r) { maxx[rt] = val; return; }
	int mid = (l + r) >> 1;
	update(lson , l , mid , pos , val);
	update(rson , mid + 1 , r , pos , val);
	push_up(rt);
}

int query(int rt,int l,int r,int al,int ar) {
	if (l > ar || r < al) return -1;
	if (l >= al && r <= ar) return maxx[rt];
	int mid = (l + r) >>1;
	return max(query(lson , l , mid , al , ar) , query(rson , mid + 1 , r , al , ar));
}

int find_right(int rt,int l,int r,int al,int ar,int lim) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (mid >= ar) return find_right(lson , l , mid , al , ar , lim);
	if (mid + 1 <= al) return find_right(rson , mid + 1 , r , al , ar , lim);
	if (maxx[lson] > lim) return find_right(lson , l , mid , al , ar , lim);
	return find_right(rson , mid + 1 , r , al , ar , lim);
} 

int find_left(int rt,int l,int r,int al,int ar,int lim) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (mid >= ar) return find_left(lson , l , mid , al , ar , lim);
	if (mid + 1 <= al) return find_left(rson , mid + 1 , r , al , ar , lim);
	if (maxx[rson] > lim) return find_left(rson , mid + 1 , r , al , ar , lim);
	return find_left(lson , l , mid , al , ar , lim);
} 

int main(){ 
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%d" , &h[i]);
	}
	build(1 , 1 , n);
	while (m--) {
		char ch[5];
		scanf("%s" , ch);
		if (ch[0] == 'U') {
			int x , y;
			scanf("%d %d" , &x , &y);
			h[x] = y;
			update(1 , 1 , n , x , y);
			continue;
		}
		int pos;
		scanf("%d" , &pos);
		int lef = query(1 , 1 , n , 1 , pos);
		int rig = query(1 , 1 , n , pos , n);
		if (ch[0] == 'L' &&  lef == h[pos]) { 
			printf("%d\n" , pos);
			continue;
		} 
		if (ch[0] == 'R' &&  rig == h[pos]) {
			printf("%d\n" , pos);
			continue;
		} 
		if (lef < rig) printf("%d\n" , find_right(1 , 1 , n , pos + 1 , n , lef));
		else printf("%d\n" , find_left(1 , 1 , n , 1 , pos - 1 , rig));
	} 
} 

