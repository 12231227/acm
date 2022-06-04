#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

bool vis[maxn + 11] = {false};
int prime[maxn + 11];
int pos[maxn + 11] = {0};
int cnt = 0;

void pre() {
	for (int i = 2; i <= maxn; i++) {
		if (!vis[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt; j++) {
			if (i * prime[j] > maxn) break;
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	pre();
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		if (x == 1) continue;
		int j = 1;
		while (true) {
			if (x % prime[j] == 0) { 
				ans += 1ll * (n - i + 1) * (i - pos[prime[j]]);
				pos[prime[j]] = i;
				while (x % prime[j] == 0) x /= prime[j];
			} 
			if (x == 1) break;
			if (!vis[x]) { 
				ans += 1ll * (n - i + 1) * (i - pos[x]);
				pos[x] = i;
				break;
			} 
			j++;
		} 
	} 
	printf("%lld\n" , ans);
} 

