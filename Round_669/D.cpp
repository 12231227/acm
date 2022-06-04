#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 3e5;
int h[maxn + 11],f[maxn + 11];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	f[1] = 0;
	stack <int> smax,smin;
	smax.push(1); smin.push(1);
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + 1;
		bool flag = true;
		while (!smax.empty() && h[smax.top()] >= h[i]) { if (flag) f[i] = min(f[i] , f[smax.top()] + 1); if (h[smax.top()] == h[i]) flag = false; smax.pop(); }
		if (flag && !smax.empty()) f[i] = min(f[i] , f[smax.top()] + 1); smax.push(i);
		flag = true;
		while (!smin.empty() && h[smin.top()] <= h[i]) { if (flag) f[i] = min(f[i] , f[smin.top()] + 1); if (h[smin.top()] == h[i]) flag = false; smin.pop(); }
		if (flag && !smin.empty()) f[i] = min(f[i] , f[smin.top()] + 1); smin.push(i);
	} 
	cout << f[n] << endl;
} 
