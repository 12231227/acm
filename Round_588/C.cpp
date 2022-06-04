#include <bits/stdc++.h>
using namespace std;

int ans;
int n,m;
pair<int,int> edge[100];
int a[100];

int check(){
	bool vis[7][7] = {false};
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = edge[i].first;
		int v = edge[i].second;
		u = a[u];
		v = a[v];
		if (u > v) swap(u , v);
		if (vis[u][v] == false) { 
			cnt++;
			vis[u][v] = true;
		} 
	}
	return cnt;
}

void dfs(int ind,int x) {
	if (ind == n) {
		ans = max(ans , check());
		return;
	} 
	for (int i = 1; i <= 6; i++) {
		a[ind + 1] = i;
		dfs(ind + 1 , i);
	}
} 

int main(){
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= m; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		edge[i] = make_pair(u , v);
	} 
	ans = 0;
	for (int i = 1; i <= 6; i++) {
		a[1] = i;
		dfs(1,i);
	}
	printf("%d\n",ans);
} 

