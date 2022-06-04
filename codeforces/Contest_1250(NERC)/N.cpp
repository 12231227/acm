#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int maxn = 2e5;
int tot;
vector<int> v, ins[maxn + 11];
vector<pair<int, int>> edge[maxn + 11];
int deg[maxn + 11];
bool vp[maxn + 11], ve[maxn + 11];
pair<int, int> g[maxn + 11];
map<pair<int, int>, int> mpedge;

int getid(int x) { return lower_bound(all(v), x) - v.begin() + 1; }

void dfs(int x)
{
	if (!vp[x])
		ins[tot].pb(x);
	vp[x] = true;
	for (auto pi : edge[x])
	{
		int v = pi.first;
		if (ve[pi.second])
			continue;
		ve[pi.second] = true;
		deg[x]++;
		deg[v]++;
		dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		v.clear();
		mpedge.clear();
		tot = 0;
		for (int i = 1; i <= n; i++)
		{
			int x, y;
			cin >> x >> y;
			g[i] = { x, y };
			v.pb(x);
			v.pb(y);
		}
		sort(all(v));
		v.erase(unique(all(v)), v.end());
		for (int i = 1; i <= n; i++)
		{
			g[i].first = getid(g[i].first);
			g[i].second = getid(g[i].second);
			int x = g[i].first; int y = g[i].second;
			if (x > y) swap(x, y);
			if (mpedge[make_pair(x, y)]){
				ve[i] = true;
				continue;
			}
			else{
				mpedge[make_pair(x, y)]++;
				ve[i] = false;
				edge[g[i].first].pb(make_pair(g[i].second, i));
				edge[g[i].second].pb(make_pair(g[i].first, i));
			}
		}
		for (int i = 1; i <= v.size(); i++)
			vp[i] = false, deg[i] = 0;
		for (int i = 1; i <= v.size(); i++)
		{
			if (!vp[i])
			{
				tot++;
				dfs(i);
			}
		}
		cout << tot - 1 << endl;
		for (int i = 1; i < tot; i++)
		{
			int u = 0;
			for (auto j : ins[i])
				if (deg[j] == 1)
					u = j;
			if (!u)
				u = ins[i][0];
			cout << edge[u][0].second << " " << v[u - 1] << " " << v[ins[i + 1][0] - 1] << endl;
			deg[ins[i + 1][0]]++;
			ins[i].clear();
		}
		ins[tot].clear();
		for (int i = 1; i <= v.size(); i++)
			edge[i].clear();
	}
	//system("pause");
	return 0;
}
