#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int sg[100][100][100][100];

int mex(vector <int> v) { 
	sort(all(v));
	for (int i = 0; i < v.size(); i++) if (v[i] != i) return i;
	return v.size();
}

int dfs(int a,int b,int c,int d) { 
	if (sg[a][b][c][d] != -1) return sg[a][b][c][d];
	vector <int> v;
	if (a > 0 && a + b + c + d >= 2) v.pb(dfs(a - 1 , b , c , d));
	if (b >= 2) v.pb(dfs(a , b - 2 , c + 1 , d));
	if (b >= 1 && c >= 1) v.pb(dfs(a , b - 1 , c - 1 , d + 1));
	return sg[a][b][c][d] = mex(v);
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(sg , -1 , sizeof(sg));
	for (int i = 0; i <= 50; i++)
		for (int j = 0; j <= 50; j++)
			for (int k = 0; k <= 50; k++)
				for (int p = 0; p <= 50; p++)
					sg[i][j][k][p] = dfs(i , j , k , p);
	int n,m;
	while (cin >> n >> m){
		for (int i = 0; i <= 50; i++ , puts(""))
			for (int j = 0; j <= 50; j++)
				printf("%d " , sg[n][m][i][j]);
	}
} 
