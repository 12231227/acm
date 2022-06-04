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
	int n; cin >> n;
	int ans = 0;
	int mx = 1e6;
	for (int i = 1; i <= n; i++) {
		int p; char ch[111];
		cin >> p >> ch + 1;
		int m = strlen(ch + 1);
		int a[5];
		a[2] = 2 , a[0] = a[1] = 1;
		for (int j = 1; j <= m; j++)
			if (ch[j] >= '0' && ch[j] <= '2') a[ch[j] - '0']--;
		if (a[0] <= 0 && a[1] <= 0 && a[2] <= 0) {
			if (mx > p) { mx = p; ans = i;}
		}
	}
	cout << ans << endl;
} 