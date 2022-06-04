#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int lef[maxn + 11][maxn + 11],st[maxn + 11][maxn + 11][20];
int lg[maxn + 11];
char ch[maxn + 11];
int n,m;

int query(int x,int y,int l) {
	int j = lg[l];
	return min(st[x][y][j] , st[x - l + (1 << j)][y][j]);
}

bool check(int l) {
	for (int i = l; i <= n; i++)
		for (int j = l; j <= m; j++)
			if (query(i , j , l) >= l) return true;
	return false;
}

int main(){
	for (int i = 1; i <= 1000; i++){
		for (int j = 0; ; j++)
			if ((1 << j) > i) {
				lg[i] = j - 1;
				break;
			}
	}
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) { 
		scanf("%s" , ch + 1);
		lef[i][1] = st[i][1][0] = 1;
		for (int j = 2; j <= m; j++){ 
			if (ch[j] == ch[j - 1]) lef[i][j] = lef[i][j - 1] + 1;
			else lef[i][j] = 1;
			st[i][j][0] = lef[i][j];
		} 
	} 
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = (1 << j); i <= n; i++)
			for (int k = 1; k <= m; k++)
				st[i][k][j] = min(st[i][k][j - 1] , st[i - (1 << (j - 1))][k][j - 1]);
	int l = 1; int r = min(n , m);
	int ans = 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) { ans = mid; l = mid + 1; }
		else r = mid - 1;
	} 
	printf("%d\n" , ans * ans);
} 

