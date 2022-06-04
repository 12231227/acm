#include <bits/stdc++.h>
using namespace std;

int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
int a[55][55];
bool vis[55][55];
char ch[55];

int n,m;

void dfs(int x,int y) {
	vis[x][y] = true;
	for (int i = 0; i < 4; i++)
		if (x + dx[i] > 0 && x + dx[i] <= n && y + dy[i] > 0 && y + dy[i] <= m && !vis[x + dx[i]][y + dy[i]] && a[x + dx[i]][y + dy[i]] != 1) 
			dfs(x + dx[i] , y + dy[i]);
}

int main(){
	int t;
	for (scanf("%d",&t);t;t--) {
		scanf("%d %d",&n,&m);
		for (int i = 1; i <= n; i++){
			scanf("%s" , ch + 1);
			for (int j = 1; j <= m; j++) {
				if (ch[j] == '.') a[i][j] = 0;
				else if (ch[j] == '#') a[i][j] = 1;
				else if (ch[j] == 'G') a[i][j] = 2;
				else a[i][j] = 3;
				vis[i][j] = false;
			}
		}
		if (a[n][m] != 1) dfs(n , m);
		bool flag = true;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i][j] == 3 && vis[i][j]) {
					for (int k = 0; k < 4; k++)
						if (i + dx[k] > 0 && i + dx[k] <= n && j + dy[k] > 0 && j + dy[k] <= m && vis[i + dx[k]][j + dy[k]]) {
							if (a[i + dx[k]][j + dy[k]] == 2) flag = false;
							else if (a[i + dx[k]][j + dy[k]] == 0) a[i + dx[k]][j + dy[k]] = 1;
						}
				}
		if (!flag) { puts("No"); continue; }
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) vis[i][j] = false;
		if (a[n][m] != 1) dfs(n , m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i][j] == 2 && !vis[i][j]) flag = false;
		if (flag) puts("Yes"); else puts("No");
	}
} 

