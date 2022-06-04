#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;

const int maxn = 3e5;
int pos[maxn + 11];
int lazy[4 * maxn + 11],tree[4 * maxn + 11];

void push_down(int rt) {
	int val = lazy[rt]; lazy[rt] = 0;
	tree[lson] += val; lazy[lson] += val;
	tree[rson] += val; lazy[rson] += val;
} 

void update(int rt,int l,int r,int al,int ar,int val) {
	if (l > ar || r < al) return;
	if (l >= al && r <= ar) {
		tree[rt] += val;
		lazy[rt] += val;
		return;
	}
	push_down(rt);
	int mid = (l + r) >> 1;
	update(lson , l , mid , al , ar , val);
	update(rson , mid + 1 , r , al , ar , val);
	tree[rt] = min(tree[lson] , tree[rson]);
} 

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		pos[x] = i;
	}
	int ans = n + 1;
	for (int i = 1; i <= n; i++) {
		while (tree[1] >= 0) { 
			ans--;
			update(1 , 1 , n , 1 , pos[ans] , -1);
		} 
		cout << ans << " ";
		int x; cin >> x;
		update(1 , 1 , n , 1 , x , 1);
	} 
} 

