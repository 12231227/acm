#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

vector <int> v;
int a[1010];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		v.clear();
		for (int i = 1; i + 2 <= n; i += 3) {
			int s = a[i] + a[i + 1] * 2 + a[i + 2] * 4;
			if (s == 0) v.pb(0),v.pb(0),v.pb(0);
			if (s == 1 || s == 2 || s == 4) v.pb(0),v.pb(0);
			if (s == 3) v.pb(1),v.pb(1),v.pb(0);
			if (s == 5) v.pb(1),v.pb(1);
			if (s == 6) v.pb(0),v.pb(1),v.pb(1);
			if (s == 7)  v.pb(1),v.pb(1);
		}
		int res = n % 3;
		if (res == 1) {
			if (!a[n]) v.pb(0);
		}
		else if (res == 2) {
			if (a[n] && a[n - 1]) v.pb(1),v.pb(1);
			else if (!a[n] && !a[n - 1]) v.pb(0),v.pb(0);
			else v.pb(0);
		}
		printf("%d\n" , v.size());
		for (auto u : v) printf("%d " , u);
		printf("\n");
	} 
} 
