#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pb push_back
#define all(x) (x).begin(),(x).end()

using namespace std;

const int maxn = 1e5;

vector <int> row[maxn + 11],cul[maxn + 11];
pair<int,int> p1[maxn + 11],p2[maxn + 11];

signed main(){
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int x,y;
		cin >> x >> y;
		p1[i] = make_pair(x , y);
		p2[i] = make_pair(y , x);
	}
	sort(p1 + 1 , p1 + 1 + k);
	for (int i = 1; i <= n; i++) row[i].pb(0);
	for (int i = 1; i <= k; i++) {
		row[p1[i].first].pb(p1[i].second);
	}
	for (int i = 1; i <= n; i++) row[i].pb(m + 1);
	sort(p2 + 1 , p2 + 1 + k);
	for (int i = 1; i <= m; i++) cul[i].pb(0);
	for (int i = 1; i <= k; i++) {
		cul[p2[i].first].pb(p2[i].second);
	}
	for (int i = 1; i <= m; i++) cul[i].pb(n + 1);
	int ux,dx,ly,ry;
	ux = 0; dx = n + 1; ly = 0; ry = m + 1;
	int x,y;
	int dir = 1;
	x = y = 1;
	ll dis = 1;
	if (row[1][1] == 2) dir = 2;
	while (true) {
		if (dir == 1) { 
			int To = row[x][lower_bound(all(row[x]) , y) - row[x].begin()] - 1;
			To = min(To , ry - 1);
			if (To == y) break;
			ux = min(ux , x);
			dis += To - y;
			dir = 2;
			y = ry = To;
		}
		else if (dir == 2) {
			int To = cul[y][lower_bound(all(cul[y]) , x) - cul[y].begin()] - 1;
			To = min(To , dx - 1);
			if (To == x) break;
			ux = max(x , ux);
			dis += To - x;
			dir = 3;
			x = dx = To;
		}
		else if (dir == 3) {
			int To = row[x][lower_bound(all(row[x]) , y) - row[x].begin() - 1] + 1;
			To = max(To , ly + 1);
			ry = min(y , ry);
			if (To == y) break;
			dis += y - To;
			dir = 4;
			y = ly = To;
		}
		else {
			int To = cul[y][lower_bound(all(cul[y]) , x) - cul[y].begin() - 1] + 1;
			To = max(To , ux + 1);
			ly = max(ly , y);
			if (To == x) break;
			dis += x - To;
			dir = 1;
			x = ux = To;
		}
	}
	if (dis + k == n * m) printf("Yes\n"); else printf("No\n");
}

