#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000;
int val[maxn + 11];
vector <int> edge[maxn + 11];
int c[maxn + 11];
vector <pair<int,int> > vec;
bool flag = true;
int tot = 0;

void get(int x) {
	vec.push_back(make_pair(val[x] , x));
	for (auto v : edge[x]) {
			get(v);
		}
}

void dfs(int x) { 
	if (!flag) return;
	for (auto v : edge[x]) { 
		dfs(v);
	} 
	if (edge[x].size() == 0) { val[x] = ++tot; if (c[x] > 0) flag = false; return; } 
	vec.clear();
	for (auto v : edge[x]) { 
		get(v);
	} 
	sort(vec.begin() , vec.end());
	if (c[x] > vec.size()) { flag = false; return; }
	if (c[x] == 0) val[x] = vec[0].first; else val[x] = vec[c[x] - 1].first + 1;
	for (int i = c[x]; i < vec.size(); i++) val[vec[i].second]++;
	tot++;
} 

int main(){
	int n;
	scanf("%d" , &n);
	int root = 0;
	for (int i = 1; i <= n; i++) { 
		int u;
		scanf("%d %d" , &u , &c[i]);
		if (u == 0) { root = i; continue; } 
		edge[u].push_back(i);
	}
	dfs(root);
	if (!flag) { printf("NO\n"); return 0; }
	printf("YES\n");
	for (int i = 1; i <= n; i++) printf("%d " , val[i]);
	return 0;
}
