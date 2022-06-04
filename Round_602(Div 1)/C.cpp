#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

vector <vector <int> > vis,sum,q;
int head[maxn + 11],tail[maxn + 11];

int query(int x,int y,int r) { return sum[x + r - 1][y + r - 1] - sum[x - 1][y + r - 1] - sum[x + r - 1][y - 1] + sum[x - 1][y - 1]; }

int n,m;
char ch[maxn + 11];

bool check(int t) { 
	for (int i = 1; i <= m; i++) head[i] = 1 , tail[i] = 0;
	int r = 2 * t + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) vis[i][j] = 0;
	for (int i = 1; i <= n; i++) { 
		int last = 0;
		for (int j = 1; j <= m; j++) { 
			if (query(i , j , 1) == 0) continue;
			while (head[j] <= tail[j] && q[j][head[j]] + r - 1 < i)  head[j]++;
			if (i <= n - r + 1 && j <= m - r + 1 && query(i , j , r) == r * r) { 
				q[j][++tail[j]] = i;
				vis[i + t][j + t] = 1;
			} 
			if (head[j] <= tail[j]) last = j;
			if (last == 0 || last + r - 1 < j) return false;
		} 
	} 
	return true;
} 

int main(){ 
	scanf("%d %d",&n,&m);
	sum.resize(n + 1);
	vis.resize(n + 1);
	q.resize(m + 1);
	for (int i = 0; i < m + 1; i++) q[i].resize(n + 1);
	for (int i = 0; i < n + 1; i++) sum[i].resize(m + 1),vis[i].resize(m + 1);
	for (int i = 1; i <= n; i++) { 
		scanf("%s" , ch + 1);
		for (int j = 1; j <= m; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (ch[j] == 'X');
	} 
	int l = 1;
	int r = (min(n , m) - 1) / 2;
	int ans = 0;
	while (l <= r) { 
		int mid = (l + r) / 2;
		if (check(mid))
			{ ans = mid; l = mid + 1; } else r = mid - 1;
	} 
	printf("%d\n" , ans);
	check(ans);
	if (ans != 0){ 
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				printf("%c%s", vis[i][j] ? 'X' : '.' , j == m ? "\n" : "");
	} 
	else {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				printf("%c%s",query(i , j , 1) ? 'X' : '.' , j == m ? "\n" : "");
	}
} 
