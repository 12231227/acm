#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector <int> vec[maxn + 11],edge[maxn + 11],ans;
int can[maxn + 11];

void dfs(int x,int fa) {
	if (vec[x].size() > 1 || (!vec[x].empty() && vec[x][0] == fa)) return;
	vec[x].push_back(fa);
	for (auto v : edge[x]) dfs(v , fa);
}

int main(){
	int n,m,t;
	scanf("%d %d %d",&n,&m,&t);
	int tot = 0;
	for (int i = 1; i <= m; i++) {;
		int u,v;
		scanf("%d %d",&u,&v);
		if (v == t) can[++tot] = u;
		else edge[v].push_back(u);
	}
	for (int i = 1; i <= tot; i++) dfs(can[i] , can[i]);
	for (int i = 1; i <= tot; i++)
		if (vec[can[i]].size() == 1) ans.push_back(can[i]);
	printf("%d\n" , ans.size());
	for (auto v : ans) printf("%d\n" , v);
} 

