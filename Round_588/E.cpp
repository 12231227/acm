#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5;
const ll mol = 1e9 + 7;
ll a[maxn + 11];	
map<ll,int> mp[maxn + 11];
vector <int> edge[maxn + 11];
ll ans;

ll gcd(ll a,ll b) { return b == 0 ? a : gcd(b , a % b); } 

void dfs(int x,int fa) { 
	mp[x][a[x]]++;
	for (int i = 0; i < edge[x].size(); ++i) { 
		int v = edge[x][i];
		if (v == fa) continue;
		map <ll,int> ::iterator it;
		for (it = mp[x].begin(); it != mp[x].end(); it++) { 
			mp[v][gcd((*it).first , a[v])] += (*it).second;
		} 
		dfs(v , x);
	} 
} 

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	for (int i = 1; i < n; i++) { 
		int u,v;
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	} 
	ans = 0;
	dfs(1,0);
	for (int i = 1; i <= n; i++){
		map <ll,int> ::iterator it;
		for (it = mp[i].begin(); it != mp[i].end(); it++) ans = (ans + (*it).first * (*it).second % mol) % mol;
	}
	printf("%lld\n",ans);
} 

