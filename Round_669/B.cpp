#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int a[1010];
bool vis[1010];

int gcd(int a,int b) { return b == 0 ? a : gcd(b , a % b); }

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) { cin >> a[i]; vis[i] = false; }
		int g = 0;
		for (int i = 1; i <= n; i++) {
			int mx = 0 , ind = 0;
			for (int j = 1; j <= n; j++)
				if (!vis[j] && gcd(a[j] , g) > mx) { mx = gcd(a[j] , g); ind = j; }
			g = gcd(a[ind] , g); vis[ind] = true;
			printf("%d " , a[ind]);
		}
		printf("\n");
	}
} 