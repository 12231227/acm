#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
using namespace std;

const int maxn = 2e5;
int cnt[maxn + 11],c[maxn + 11];
vector <int> res[maxn + 11];

int main(){
	int n,k;
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		cnt[m]++;
	}
	for (int i = 1; i <= k; i++) cin >> c[i];
	int sum = 0;
	int ans = 0;
	for (int i = k; i >= 1; i--) {
		sum += cnt[i];
		int tmp = sum / c[i];
		if (sum % c[i] != 0) tmp++;
		ans = max(ans , tmp);
	}
	cout << ans << endl;
	int ind = 1;
	for (int i = k; i >= 1; i--) {
		for (int j = 1; j <= cnt[i]; j++) {
			if (c[i] - res[ind].size() > 0) res[ind].pb(i);
			else {
				while (c[i] - res[ind].size() == 0) {
					ind++;
					if (ind > ans) ind = 1;
				}
				res[ind].pb(i);
			}
		}
	}
	for (int i = 1; i <= ans; i++) {
		cout << res[i].size();
		for (auto p : res[i]) cout << " " << p;
		cout << endl;
	}
} 
