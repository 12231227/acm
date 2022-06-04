#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int h[1000],a[1000],b[1000];
int g[1000][1000],f[1000][1000];

int main(){ 

	ios_base::sync_with_stdio(0),
 cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++){
		for (int x = 0; x <= 100; x++)
			if (x >= h[i]) f[i][x] = g[i - 1][x] + (x - h[i]) * a[i];
			else f[i][x] = g[i - 1][x] + (h[i] - x) * b[i];
		g[i][0] = f[i][0];
		for (int x = 1; x <= 100; x++)
			g[i][x] = min(g[i][x - 1] , f[i][x]);
		for (int x = 2; x <= 10; x++) printf("%d " , g[i][x] - g[i][x - 1]); puts("");
	}
	printf("%d\n" , g[n][100]);
} 
