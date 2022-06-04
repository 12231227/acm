#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 5000;

int ans[maxn + 11];
vector <int> v;
vector <int> g[maxn + 11];
int d[maxn + 11];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= m; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if (u < v) ans[i] = 1; else ans[i] = 2;
		d[v]++;
		g[u].push_back(v);
	} 
	for (int i = 1; i <= n; i++) if (d[i] == 0) v.push_back(i);
	for (int i = 0; i < v.size(); i++){
		int x = v[i];
		for (int j = 0; j < g[x].size(); j++)
		 if (--d[g[x][j]] == 0) v.push_back(g[x][j]);
	} 
	if (v.size() == n){
		printf("1\n");
		for (int i = 1; i <= m; i++) printf("1 ");
	}
	else{
		printf("2\n");
		for (int i = 1; i <= m; i++) printf("%d ",ans[i]);
	} 
} 

