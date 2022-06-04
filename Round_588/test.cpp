#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int maxn = 1e5;
const ll mol = 1e9 + 7;
ll a[maxn + 11];
ll num[maxn + 11];
vector <ll> g[maxn + 11];
vector <int> edge[maxn + 11];
ll ans;

ll gcd(ll a,ll b) { return b == 0 ? a : gcd(b , a % b); }
 
void dfs(int x,int fa) {
	if (a[x] == 1) num[x]++; else g[x].push_back(a[x]);
	for (int i = 0; i < edge[x].size(); i++) { 
		int v = edge[x][i];
		if (v == fa) continue;
		if (a[v] == 0) {
			for (int j = 0; j < g[x].size(); j++) {
				ans = (ans + g[x][j]) % mol;
				g[v].push_back(g[x][j]);
			}
			num[v] += num[x];
		}
		else if (a[v] == 1) num[v] += num[x];
		else {
			for (int j = 0; j < g[x].size(); j++) {
				ll tmp = gcd(g[x][j] , a[v]);
				ans = (ans + tmp) % mol;
				g[v].push_back(tmp);
			}
			num[v] += num[x];
		} 
		ans = (ans + num[x]) % mol;
		dfs(v , x);
	} 
} 

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%lld",&a[i]);
	for (int i = 1; i < n; i++) { 
		int u,v;
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	} 
	ans = 0;
	dfs(1,0);
	for (int i = 1; i <= n; i++) ans = (ans + a[i]) % mol;
	printf("%lld\n",ans);
} 

