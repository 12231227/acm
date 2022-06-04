#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int a[5011],f[5011][5011],mm[5011];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) { cin >> a[i]; if (a[i] > n) a[i] = n; }
	memset(f , 0x3f3f3f , sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++){ 
		int mn = n * n;
		for (int j = 0; j <= n; j++) mn = min(mn , f[i - 1][j]);
		if (a[i] == 0) { f[i][0] = mn; continue; }
		f[i][0] = mn + 1;
		mm[n + 1] = n * n;
		for (int j = n; j >= 1; j--) mm[j] = min(mm[j + 1] , f[i - 1][j]);
		int mmn = f[i - 1][0];
		for (int j = 1; j < a[i]; j++) {
			mmn = min(mmn , f[i - 1][j] - j);
			f[i][j] = min(min(mn + j + 1 , mmn + j + 1) , min(mm[j] + 1 , mm[a[i]]));
		}
		mmn = min(mmn , f[i - 1][a[i]] - a[i]);
		f[i][a[i]] = min(min(mn + a[i] , mmn + a[i]) ,mm[a[i]]);
	}
	int ans = n * n;
	for (int i = 0; i <= n; i++) ans = min(ans , f[n][i]);
	cout << ans << endl;
} 
