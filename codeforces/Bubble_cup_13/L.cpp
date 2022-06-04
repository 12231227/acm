#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

typedef unsigned long long ull;

const int maxn = 1000;
const int maxm = 1e5;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
map <ull,int> mp;
ull Hash[maxn + 11],id[maxn + 11],num[maxm + 11];
int cnt[maxm + 11];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,s,d; cin >> n >> s >> d;
	for (int i = 1; i <= n; i++) Hash[i] = rng();
	for (int i = 1; i <= s; i++) { 
		int k; cin >> k;
		for (int j = 1; j <= k; j++) { 
			int x; cin >> x;
			id[i] ^= Hash[x];
		}
	}
	int mid = s / 3 + 1;
	//1 - p
	for (int i = 0; i < (1 << mid); i++) {
		ull tmp = 0;
		for (int j = 0; j < mid; j++)
			if ((i >> j) & 1) tmp ^= id[j + 1];
		num[i] = tmp;
		cnt[i] = __builtin_popcount(i);
	}
	for (int i = 0; i < (1 << (s - mid)); i++) {
		ull tmp = 0;
		for (int j = 0; j < s - mid; j++)
			if ((i >> j) & 1) tmp ^= id[mid + j + 1];
		if (mp.count(tmp)) mp[tmp] = min(mp[tmp] , __builtin_popcount(i));
		else mp[tmp] = __builtin_popcount(i);
	}
	for (int i = 1; i <= d; i++) { 
		int k; cin >> k;
		int ans = n + 100;
		ull bit = 0;
		for (int j = 1; j <= k; j++) {
			int x; cin >> x; bit ^= Hash[x];
		}
		for (int j = 0; j < (1 << mid); j++) {
			if (mp.count(bit ^ num[j])) ans = min(ans , mp[bit ^ num[j]] + cnt[j]);
		}
		if (ans > n) printf("-1\n"); else printf("%d\n" , ans);
	} 
} 

