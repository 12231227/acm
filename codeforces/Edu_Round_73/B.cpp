#include <bits/stdc++.h>
using namespace std;

int n;
int vis[111][111];
const int dx[8] = {-2,-1,1,2,2,1,-1,-2};
const int dy[8] = {1,2,2,1,-1,-2,-2,-1};

void dfs(int color,int x,int y) {
	if (vis[x][y] != 0) return;
	vis[x][y] = color;
	for (int i = 0; i < 8; i++)
	 if (x + dx[i] > 0 && x + dx[i] <= n && y + dy[i] > 0 && y + dy[i] <= n)
	  dfs(-color , x + dx[i] , y + dy[i]);
} 

int main(){
	scanf("%d",&n);
	dfs(-1,1,1);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
		 printf("%s",vis[i][j] == -1 ? "W" : "B");
		printf("\n");
	}
}

