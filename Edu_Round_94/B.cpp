#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int p,f; cin >> p >> f;
		int cs,cw; cin >> cs >> cw;
		int s,w; cin >> s >> w;
		if (s > w) { swap(s , w); swap(cs , cw); }
		int ans = 0;
		for (int i = 0; i <= cs; i++) {
			if (1ll * i * s > p) break;
			int j = (p - i * s) / w; j = min(j , cw);
			int cnt = i + j;
			int _s = cs - i , _w = cw - j;
			if (1ll * _s * s >= f) cnt += f / s;
			else cnt += _s + min((f - _s * s) / w , _w);
			ans = max(ans , cnt);
		}
		cout << ans << endl;
	}
} 