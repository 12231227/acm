#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

const int maxn = 75;

struct node{
	int a,b,num;
}p[maxn + 11];

int f[maxn + 11][maxn + 11][2];
vector <int> v1,v2;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		int n,k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) { cin >> p[i].a >> p[i].b; p[i].num = i; }
		sort(p + 1 , p + 1 + n , [&](node a,node b) { return a.b < b.b; });
		memset(f , 0 , sizeof(f));
		for (int i = 1; i <= n; i++) {
			f[i][0][0] = f[i - 1][0][0] + p[i].b * (k - 1);
			for (int j = 1; j <= min(k , i); j++) {
				if (i > j) f[i][j][0] = max(f[i - 1][j][0] , f[i - 1][j][1]) + p[i].b * (k - 1);
				f[i][j][1] = max(f[i - 1][j - 1][0] , f[i - 1][j - 1][1]) + p[i].b * (j - 1) + p[i].a;
			}
		}
		v1.clear(); v2.clear();
		int x = n; int y = k;
		while (x) {
			if (f[x][y][0] >= f[x][y][1]) {
				v2.pb(x);
				x--;
			}
			else {
				v1.pb(x);
				x--; y--;
			}
		}
		reverse(v1.begin() , v1.end());
		int m = (int)v1.size() + 2 * (int)v2.size();
		cout << m << endl;
		for (int i = 0; i < v1.size() - 1; i++) cout << p[v1[i]].num << " ";
		for (auto u : v2) cout << p[u].num << " " << -p[u].num << " ";
		cout << p[v1.back()].num << endl;
	}
} 

