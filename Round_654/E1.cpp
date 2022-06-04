#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

vector <int> ans;
int a[2010];

int main(){
	int n,p;
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1 , a + 1 + n , [&](int a,int b) { return a > b; });
	for (int i = a[1] - n + 1; i < a[1]; i++) {
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if ((n - max(a[j] - i + 1 , 1) + 1 - j + 1) % p == 0) { flag = false; break; }
		}
		if (flag) ans.pb(i);
	}
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << " ";
}
