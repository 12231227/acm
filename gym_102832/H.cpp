#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define rep(i,k,n) for (int i=k;i<n;i++)
#define pii pair<int,int>
# define sz(x) (int)(x).size()
#define pll pair<ll,ll>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
struct edge
{
	int to, re, c;
};

vector<edge> g[maxn];
vector<int> rg[maxn];
int n, m, s1, t1;
int iter[maxn];
int d[maxn];
int c[maxn];
int can[maxn];
int V;
void addedge(int x, int y)
{
//	printf("%d-->%d", x, y);
	if (!can[x] || !can[y]) return;
	rg[x].pb(y);
	rg[y].pb(x);
}
void add_edge(int x, int y, int cap)
{
	if (!can[x] || !can[y]) return;
	g[x].pb((edge) {y, sz(g[y]), cap});
	g[y].pb((edge) {x, sz(g[x]) - 1, 0});
	return;
}
void init()
{
	s1 = V;
	t1 = V + 1;
	V = t1 + 1;
	can[t1] = 1;
	can[s1] = 1;
	rep(i, 0, V)
	{
		g[i].clear();
	}
	rep(i, 0, s1)
	{
		int tmp = i;
		int ss = 0;
		while (tmp)
		{
			ss += tmp % 10;
			tmp = tmp / 10;
		}
		if (ss % 2)
		{
			add_edge(s1, i, 1);
			for (auto v : rg[i])
			{
				add_edge(i, v, 1);
			}
		}
		else {
			add_edge(i, t1, 1);
		}
	}

}
void bfs()
{
	queue<int> q;
	while (!q.empty())q.pop();
	q.push(s1);
	d[s1] = 0;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		rep(i, 0, sz(g[v]))
		{
			edge &e = g[v][i];
			if (d[e.to] < 0 && e.c > 0 && can[e.to])
			{
				d[e.to] = d[v] + 1;

				q.push(e.to);
			}
		}
	}
}

int dfs(int x, int f)
{
	if (x == t1 || !f) return f;
	int sf = 0;
	for (int &i = iter[x]; i < sz(g[x]); i++)
	{
		edge &e = g[x][i];
		if (d[e.to] > d[x] && e.c > 0 && can[e.to])
		{
			int flow = dfs(e.to, min(f, e.c));
			if (flow > 0)
			{
				e.c -= flow;
				g[e.to][e.re].c += flow;
				sf += flow;
				f -= flow;
				if (!f) break;
			}
		}
	}
	return sf;
}
int flow()
{
	int flow = 0;
	for (;;)
	{
		memset(d, -1, sizeof(int) * (V) );
		bfs();
		if (d[t1] < 0) return flow;
		memset(iter, 0, sizeof(int) * (V));
		flow += dfs(s1, inf);
	}
	return flow;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {

		int m, n, s; cin >> m >> n >> s;
		int lim = 10;
		for (int i = 1; i < m; i++) lim *= 10;
		for (int i = 0; i < lim; i++) can[i] = true;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			can[x] = false;
		}
		for (int i = 0; i <= lim; i++) rg[i].clear();
		int maxtt = 0;
		for (int i = 0; i < lim; i++) {
			int x = i , op = 1;
			for (int j = 0; j < m; j++) {
				int cur = x % 10;
				if (cur) addedge(i , i - op); else addedge(i , i + 9 * op);
				if (cur < 9) addedge(i , i + op); else addedge(i , i - 9 * op);
				op *= 10; x /= 10;
			}
		}
		// bool go = false;
		// for (auto pi : rg[s]) if (can[pi.to]) go = true;
		V = lim;
		init();
		int ans1 = flow();
		can[s] = false;
		init();
		int ans2 = flow();
		if (ans1 == ans2) cout << "Bob" << endl; else cout << "Alice" << endl;
	} 
} 
