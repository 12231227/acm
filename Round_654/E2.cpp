#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

const int maxn = 1e5;
vector <int> ans;
int n,p;
int a[maxn + 11],pos[maxn + 11];
vector <int> ton[maxn + 11];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1 , a + 1 + n , [&](int a,int b) { return a > b; });
	int r = n;
	bool flag = true;
	int m = max(a[1] - n + 1 , a[n]);
	for (int i = 1; i <= n; i++) {
		if (a[i] - m < 0) {
			r = min(r , i - 1);
			if ((n - i + 1) % p == 0) flag = false;
		}
		else {
			ton[((n - (a[i] - m) - i + 1) % p + p) % p].pb(i);
			pos[i] = ((n - (a[i] - m) - i + 1) % p + p) % p;
		}
	}
	int out = p - 1;
	if (flag && ton[0].empty()) ans.pb(m);
	for (int x = m + 1; x < a[1]; x++) {
		if (!flag) break;
		for (int i = r; i >= 1; i--)
			if (a[i] - x < 0) {
				if ((n - i + 1) % p == 0) flag = false;
				ton[pos[r]].pop_back();
				r--;
			}
			else break;
		if (!flag) break;
		if (ton[out].empty()) ans.pb(x);
		out = (out - 1 + p) % p;
	}
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << " ";
} 
