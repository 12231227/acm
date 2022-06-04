#pragma GCC optimize("Ofast", 2)
#include<bits/stdc++.h>
# define fi first
# define se second
# define ll long long
# define sz(x) (int)(x).size()
# define all(x) (x).begin(),(x).end()
# define rep(i,k,n) for (int i=k;i<n;i++)
# define pb push_back
# define mp make_pair
# define INF (1<<31-1)
# define pii pair<int,int>
using namespace std;
int n, m;
vector<int> g[1100];
int iscn[1100];

int used[1100];
int prevv[1100];
int ccnt;
int maxc;
int iscl[1100][1100];
void makec(int x, int y)
{
	iscl[x][y] = iscl[y][x] = 1;
	int l = 1;
//	printf("%d-->%d:\n", x, y);
//	system("pause");
	while (x != y)
	{
		iscn[x] = 1;
		//	printf("%d-->%d\n", x, prevv[x]);
		iscl[x][prevv[x]] = iscl[prevv[x]][x] = 1;
		l++;
		x = prevv[x];


	}
//	cout << endl;
	maxc = max(maxc, l);
	ccnt++;
}
void dfs(int u)
{
	//printf("%d:\n", u);
	used[u] = 1;
	for (auto v : g[u])
	{
		if (v == prevv[u] || used[v] == 2) continue;
		if (used[v] == 1)
		{
			makec(u, v);
			continue;
		}
		prevv[v] = u;
		dfs(v);
	}
	used[u] = 2;
}
void init()
{
	scanf("%d%d", &n, &m);
	rep(i, 0, n + 1)
	{
		iscn[i] = 0;
		used[i] = 0;
		prevv[i] = 0;
		rep(j, 0, n + 1)
		{
			iscl[i][j] = 0;
		}
	}
	maxc = 0;
	ccnt = 0;
	rep(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u );
	}
	dfs(1);
}
int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
void solve()
{
	int cnn = 0;
	int cnl = 0;
	rep(u, 1, n + 1)
	{
		bool flag = false;
		for (auto v : g[u])
		{
			if (iscl[u][v])
			{
				cnl++;
				//	printf("%d--%d\n", u, v);
			}
			else {
				flag = true;
				//	printf("%d--||%d\n", u, v);
			}
		}
		if (flag) {cnn++; }
	}
	ccnt += m - cnl / 2;
	//cout << cnl << endl;
	//cout << ccnt << maxc << endl;
	printf("%d %d %d %d\n", cnn, m - cnl / 2, ccnt / gcd(ccnt, maxc), maxc / gcd(ccnt, maxc));
}
int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		init();
		solve();
	}
}