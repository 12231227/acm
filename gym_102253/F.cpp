#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e5;
const int mol = 1e9 + 7;
int a[maxn + 11],b[maxn + 11],cnt[maxn + 11];
bool vis[maxn + 11];

int main(){ 
	int n,m;
	int c = 0;
	while (~scanf("%d %d",&n,&m)) { 
		c++;
		for (int i = 0; i < n; i++) scanf("%d",&a[i]);
		for (int i = 0; i < m; i++) scanf("%d",&b[i]) , vis[i] = false;
		for (int i = 0; i <= max(n , m); i++) cnt[i] = 0;
		for (int i = 0; i < m; i++) {
			if (vis[i]) continue;
			int x = i;
			int ct = 0;
			while (!vis[x]) { ct++; vis[x] = true; x = b[x]; }
			cnt[ct]++;
		} 
		for (int i = 0; i < n; i++) vis[i] = false;
		int ans = 1;
		for (int i = 0; i < n; i++) { 
			if (vis[i]) continue;
			int x = i;
			int ct = 0;
			while (!vis[x]) { ct++; vis[x] = true; x = a[x]; } 
			int sum = 0;
			for (int j = 1; j <= ct; j++) {
				if (ct % j != 0) continue;
				(sum += 1ll * cnt[j] * j % mol) %= mol;
			}
			ans = 1ll * ans * sum % mol;
		} 
		printf("Case #%d: ",c);
		printf("%d\n" , ans);
	} 
} 

