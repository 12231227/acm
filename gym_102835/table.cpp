#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int a[200][200][200];
int s[200][200];
int n,t;

int dfs(int x,int y) { 
	if (x + y == n - 1) return y;
	if (s[x][y]) {
		s[x][y] ^= 1;
		return dfs(x , y + 1);
	}
	else {
		s[x][y] ^= 1;
		return dfs(x + 1 , y);
	}
	
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> t;
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= n; j++) s[i][j] = 0; // L
	for (int i = 1; i < t; i++) dfs(0 , 0);
	printf("%d\n" , dfs(0 , 0));
} 
