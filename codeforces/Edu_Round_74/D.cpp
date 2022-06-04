#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 3e5;
char ch[maxn + 11];

int main(){
	int n;
	cin >> n;
	scanf("%s" , ch + 1);
	ll ans = 0;
	int cnt = 1;
	int diff = 0;
	for (int i = 2; i <= n; i++) {
		if (ch[i] != ch[i - 1]) {
			diff = 1;
			ans += cnt;
			cnt = 1;
		}
		else {
			cnt++;
			if (diff) ans++;
		}
	}
	printf("%lld\n" , 1ll * n * (n - 1) / 2 - ans);
}

