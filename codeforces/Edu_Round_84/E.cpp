#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 998244353;
const int maxn = 2e5;
ll ten[maxn + 11];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	ten[0] = 1;
	for (int i = 1; i <= n; i++) ten[i] = ten[i - 1] * 10 % mol;
	for (int i = 1; i < n; i++) {
		ll ans = 18ll * ten[n - i - 1] % mol;
		if (n - i - 1 > 0) ans = (ans + 81ll * (n - i - 1) % mol * ten[n - i - 2] % mol) % mol;
		ans = ans * 10 % mol;
		cout << ans << " ";
	} 
	cout << 10 << endl;
} 

