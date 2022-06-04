#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e6;
int prime[maxn + 11];
bool vis[maxn + 11];
int cnt = 0;

void pre(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt; j++) {
			if (i * prime[j] > n) break;
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int main(){ 
	int n = 1e6;
	pre(n);
	int t; scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		int l = upper_bound(prime + 1 , prime + 1 + cnt , sqrt(n)) - prime;
		int r = upper_bound(prime + 1 , prime + 1 + cnt , n) - prime;
		printf("%d\n" , r - l + 1);
	}
} 

