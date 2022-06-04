#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int cnt = 0;
int prime[maxn + 11];
bool vis[maxn + 11] = {false};
int res[maxn + 11],mu[maxn + 11];
vector <int> d[maxn + 11];

void pre() {
	for (int i = 1; i <= maxn; i++)
		for (int j = i; j <= maxn; j += i)
			d[j].emplace_back(i);
	mu[1] = 1;
	for (int i = 2; i <= maxn; i++) {
		if (!vis[i]) { prime[++cnt] = i; mu[i] = -1; }
		for (int j = 1; j <= cnt; j++) {
			if (i * prime[j] > maxn) break;
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				mu[i * prime[j]] = 0;
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
	for (int i = 1; i <= maxn; i++) vis[i] = false;
}

int gcd(int a,int b) { return b == 0 ? a : gcd(b , a % b); }

void upd(int x,int val) { for (auto i : d[x]) res[i] += val; }

int calc_prime(int x) {
	int ans = 0;
	for (int i : d[x]) ans += res[i] * mu[i];
	return ans;
}

int main(){
	pre();
	int n;
	scanf("%d" , &n);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d" , &x);
		ans = max(ans , 1ll * x);
		vis[x] = true;
	} 
	for (int g = 1; g <= maxn; g++) {
		stack <int> s;
		for (int i = maxn / g; i >= 1; i--) {
			if (!vis[i * g]) continue;
			int num = calc_prime(i);
			bool in = num == 0 ? true : false;
			while (num) {
				if (gcd(s.top() , i) == 1) {
					ans = max(ans , 1ll * i * s.top() * g);
					num--;
				}
				upd(s.top() , -1);
				s.pop();
			}
			if (in) {  upd(i , 1); s.push(i); }
		}
		while (!s.empty()) {
			upd(s.top() , -1);
			s.pop();
		}
	} 
	printf("%lld\n" , ans);
} 

