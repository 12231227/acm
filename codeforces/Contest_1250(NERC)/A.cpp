#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int l[maxn + 11],r[maxn + 11],pos[maxn + 11],a[maxn + 11];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) l[i] = r[i] = pos[i] = a[i] = i;
	for (int i = 1; i <= m; i++) {
		int x; cin >> x;
		if (pos[x] == 1) continue;
		int y = a[pos[x] - 1];
		swap(a[pos[x] - 1] , a[pos[x]]);
		swap(pos[x] , pos[y]);
		l[x] = min(l[x] , pos[x]);
		r[y] = max(r[y] , pos[y]);
	}
	for (int i = 1; i <= n; i++) cout << l[i] << " " << r[i] << endl;
} 

