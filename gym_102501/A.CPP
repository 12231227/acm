#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;

int c[maxn + 11],x[maxn + 11],y[maxn + 11];
vector<pair<int,int> > con[maxn + 11];
int s[maxn + 11][111],e[maxn + 11][111];
int m[maxn + 11][maxn + 11];
int ds[maxn + 11],de[maxn + 11];

int calc(int x1,int y1,int x2,int y2) {
	int sqr = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return sqr * sqr == (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) ? sqr : sqr + 1;
}

int main(){
	std::ios::sync_with_stdio(false);
	int xs,ys,xd,yd,B,T,n;
	cin >> xs >> ys >> xd >> yd >> B >> c[0] >> T;
	for (int i = 1; i <= T; i++) cin >> c[i];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l;
		cin >> x[i] >> y[i] >> l;
		for (int j = 1; j <= l; j++){
			int u,v;
			cin >> u >> v;
			con[i].push_back({u + 1 , v});
		}
	}
	for (int i = 1; i <= n; i++)
		for (auto pi : con[i]) {
			if (m[i][pi.first] == 0) m[i][pi.first] = m[pi.first][i] = c[pi.second];
			else m[i][pi.first] = m[pi.first][i] = min(m[i][pi.first] , c[pi.second]);
		}
	for (int i = 1; i <= n; i++){
		ds[i] = calc(xs , ys , x[i] , y[i]);
		de[i] = calc(xd , yd , x[i] , y[i]);
	}
	memset(s , 0x3f3f3f , sizeof(s));
	for (int i = 1; i <= n; i++)
		if (ds[i] <= B) s[i][ds[i]] = c[0] * ds[i];
	for (int j = 0; j <= B; j++)
		for (int i = 1; i <= n; i++){
				for (int k = 1; k <= n; k++) {
					int dis = calc(x[i] , y[i] , x[k] , y[k]);
					if (i == k || j < dis || !m[i][k]) continue;
					s[i][j] = min(s[i][j] , s[k][j - dis] + m[i][k] * dis);
				} 
			for (int j = 1; j <= B; j++)
				s[i][j] = min(s[i][j] , s[i][j - 1]);
		} 
	memset(e , 0x3f3f3f , sizeof(e));
	for (int i = 1; i <= n; i++)
		if (de[i] <= B) e[i][de[i]] = c[0] * de[i];
	for (int j = 0; j <= B; j++)
		for (int i = 1; i <= n; i++){
				for (int k = 1; k <= n; k++) {
					int dis = calc(x[i] , y[i] , x[k] , y[k]);
					if (i == k || j < dis || !m[i][k]) continue;
					e[i][j] = min(e[i][j] , e[k][j - dis] + m[i][k] * dis);
				} 
			for (int j = 1; j <= B; j++)
				e[i][j] = min(e[i][j] , e[i][j - 1]);
		} 
	int dis = calc(xs , ys , xd , yd);
	int ans = dis > B ? 0x3f3f3f : dis * c[0];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= B; j++) {
			ans = min(ans , s[i][j] + e[i][B - j]);
		}
	if (ans == 0x3f3f3f) cout << -1 << endl;
	else cout << ans << endl;
} 

