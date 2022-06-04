#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pb push_back
using namespace std;

const int maxn = 5e5;

int n,k;
vector<pair<int,ll> > edge[maxn + 11];
ll f[maxn + 11][3];

void dfs(int x,int fa) { 
	vector <ll> vec;
	ll ans = 0;
	for (int i = 0; i < edge[x].size(); i++) { 
		int v = edge[x][i].first;
		if (v == fa) continue;
		dfs(v , x);
		vec.pb(f[v][0] + edge[x][i].second - f[v][1]);
		ans += f[v][1];
	} 
	sort(all(vec) , greater<ll>());
	int has = 0;
	f[x][0] = f[x][1] = ans;
	for (int i = 0; i < vec.size(); i++) { 
		if (vec[i] <= 0) break;
		has++;
		if (has < k) { f[x][0] += vec[i]; f[x][1] += vec[i]; }
		else { f[x][1] += vec[i]; break; }
	} 
} 

int main(){ 
	int q;
	scanf("%d",&q);
	while (q--) { 
		scanf("%d %d",&n,&k);
		for (int i = 1; i < n; i++) { 
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			edge[u].pb(make_pair(v , w));
			edge[v].pb(make_pair(u , w));
		} 
		dfs(1 , 0);
		printf("%lld\n" , max(f[1][0] , f[1][1]));
		for (int i = 1; i <= n; i++) edge[i].clear();
		for (int i = 1; i <= n; i++) f[i][0] = f[i][1] = 0;
	} 
} 
