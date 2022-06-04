#include <cstdio>
using namespace std;

const int maxn = 1e5;
int vis[maxn + 11] = {0};
int fa[maxn + 11];
int cnt[2] = {0};
int res[2] = {0};

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) { 
		int x;
		scanf("%d",&x);
		res[x]++;
		fa[i] = x;
	} 
	for (int i = 1; i <= m; i++) { 
		int u,v;
		scanf("%d %d",&u,&v);
		if (fa[u] != fa[v]){ 
			vis[u]++;
			vis[v]++;
		} 
	} 
	for (int i = 1; i <= n; i++) if (vis[i] == 0) cnt[fa[i]]++;
	for (int i = 1; i <= n; i++) { 
		int ans = res[fa[i]] - 1;
		if (vis[i] == 0) { 
			ans += cnt[fa[i] ^ 1] * 3 + (res[fa[i] ^ 1] - cnt[fa[i] ^ 1]) * 2;
		}
		else {
			ans += vis[i] + (res[fa[i] ^ 1] - vis[i]) * 2;
		}
		 printf("%d%s",ans, i == n ? "\n" : " ");
	}
} 

