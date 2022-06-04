#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 4e5;

pair<ll,int> mx[2 * maxn + 11];
ll f[maxn + 11];
int b[maxn + 11];

int main(){
	int n;
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) scanf("%d" , &b[i]);
	for (int i = 1; i <= n; i++) {
		f[i] = f[mx[b[i] - i + maxn].second] + b[i];
		mx[b[i] - i + maxn] = {f[i] , i};
	}
	ll ans = 0;
	for (int i = 0; i <= 2 * maxn; i++) ans = max(ans , f[mx[i].second]);
	printf("%lld\n" , ans);
}