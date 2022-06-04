#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool vis[100][100];
int a[100][100];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	memset(vis,false,sizeof(vis));
	for (int i = 1; i <= n; i++)
	 for (int j = 1; j <= m; j++) { scanf("%d",&a[i][j]); if (a[i][j] == 0) vis[i][j] = true; }
	vector<pair<int,int> > v;
	for (int i = 1; i < n; i++)
	 for (int j = 1; j < m; j++){
	 	if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1){
	 	 v.push_back(make_pair(i,j));
	 	 vis[i][j] = vis[i][j + 1] = vis[i + 1][j] = vis[i + 1][j + 1] = true;
	 	}
	 }
	bool can = true;
	for (int i = 1; i <= n; i++)
	 for (int j = 1; j <= m; j++) if (vis[i][j] == false) { can = false; break; } 
	if (!can) printf("-1\n");
	else{
		printf("%d\n",v.size());
		for (int i = 0; i < v.size(); i++)
		 printf("%d %d\n",v[i].first,v[i].second);
	}
} 

