#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	long long ans = 0;
	for (int x = a; x <= b; x++) {
		int y = d - x + 1;
		if (y <= b) ans += 1ll * (c - b + 1) * (d - c + 1);
		else {
			if (y <= c) ans += 1ll * (c - y + 1) * (d - c + 1);
			int r = min(d - x , c);
			int l = max(c - x , b);
			if (r >= l) ans += 1ll * (x - c) * (r - l + 1) + 1ll * (l + r) * (r - l + 1) / 2;
		}
	}
	cout << ans << endl;
}