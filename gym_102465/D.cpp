#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 8e18;
const int maxn = 100000;

int mn[maxn + 11],mx[maxn + 11];
vector <int> in[maxn + 11],out[maxn + 11];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m;
	cin >> n >> m;
	int t;
	cin >> t;
	for (int i = 0;i < n; i++) mn[i] = m , mx[i] = -1;
	for (int i = 1; i <= t; i++) {
		int x,y;
		cin >> x >> y;
		mn[x] = min(mn[x] , y);
		mx[x] = max(mx[x] , y);
	}
	ll ans = n - 1; ll sub = 0;
	for (int i = 0; i < n; i++){
		if (mx[i] != -1) {
			ans += 2 * mx[i];
			out[mx[i]].push_back(i);
			sub += 2;
		}
		if (mn[i] != m) in[mn[i]].push_back(i);
	}
	ll add = 0;
	for (auto y : in[0]) sub -= 2;
	for (auto y : out[0]) add += 2;
	ll now = ans;
	for (int i = 1; i < m; i++) {
		now = now - sub + add;
		ans = min(ans , now);
		for (auto y : in[i]) sub -= 2;
		for (auto y : out[i]) add += 2;
	}
	cout << ans << endl;
} 
