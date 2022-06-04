#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int ans = 0;
int cur = 0;

struct node{
	int cost,val,ext;
}a[10];
int s[20];

void dfs(int pos,int res) {
	if (res == 0) {
		ans = max(ans , cur);
		return;
	}
	if (pos == 6) { 
		if (res % 648 != 0) return;
		cur += res * 10 + 388;
		ans = max(ans , cur);
		cur -= res * 10 + 388;
		return;
	}
	if (s[pos])
	for (int i = 0; i * a[pos].cost <= res ; i++) {
		if (i) cur += i * a[pos].val + a[pos].ext;
		dfs(pos + 1 , res - i * a[pos].cost);
		if (i) cur -= i * a[pos].val + a[pos].ext;
	} 
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	a[0] = node{1 , 10 , 8};
	a[1] = node{6 , 60 , 18};
	a[2] = node{28 , 280 , 28};
	a[3] = node{88 , 880 , 58};
	a[4] = node{198 , 1980 , 128};
	a[5] = node{328 , 3280 , 198};
	a[6] = node{648 , 6480 , 388};
	s[6] = 388;
	for (int i = 5; i >= 0; i--) s[i] = s[i + 1] + a[i].ext;
	dfs(0 , n);
	printf("%d\n" , ans);
} 
