#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int mol = 1e9 + 7;
int three[33];

int add(int a,int b) { a += b; if (a >= mol) a -= mol; return a; }

int dfs(int pos,int x,int y,int limx,int limy,bool flag = true) {
	if (pos == -1) return 1;
	if (!limx && !limy) return three[pos + 1];
	if (!limx) {
		int ans = 0;
		int w = (y & (1 << pos));
		ans = add(ans , 2 * dfs(pos - 1 , x , y , 0 , w == 0) % mol);
		if (w) ans = add(ans , dfs(pos - 1 , x , y , 0 , 1));
		return ans;
	}
	else if (!limy) {
		int ans = 0;
		int w = (x & (1 << pos));
		ans = add(ans , (flag ? 2 : 1) * dfs(pos - 1 , x , y , w == 0 , 0) % mol);
		if (w) ans = add(ans , dfs(pos - 1 , x , y , 1 , 0));
		return ans;
	}
	int ans = 0;
	int wx = (x & (1 << pos)) , wy = (y & (1 << pos));
	if (flag) ans = add(ans , dfs(pos - 1 , x , y , wx == 0 , wy == 0));
	if (wx) ans = add(ans , dfs(pos - 1 , x , y , 1 , wy == 0));
	if (wy) ans = add(ans , dfs(pos - 1 , x , y , wx == 0 , 1));
	return ans;
}

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	three[0] = 1;
	for (int i = 1; i <= 31; i++) three[i] = 1ll * three[i - 1] * 3 % mol;
	int t; cin >> t;
	while (t--) {
		int x,y; cin >> x >> y;
		if (x > y) swap(x , y);
		int mx = -1 , my = -1;
		for (int i = 0; i <= 30; i++) if (x & (1 << i)) mx = i;
		for (int i = 0; i <= 30; i++) if (y & (1 << i)) my = i;
		int ans = 0;
		for (int i = mx; i <= my; i++)
			ans = add(ans , 1ll * (i + 1) * dfs(i , x , y , 1 , i == my , false) % mol);
		for (int i = 0; i < mx; i++) {
			ans = add(ans , 2ll * three[i] % mol * (i + 1) % mol);
		} 
		cout << ans << endl;
	}
} 
