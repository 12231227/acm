#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e15;
const int maxn = 1e5;

ll f[maxn * 12 + 11];
ll cnt[maxn * 12 + 11];
char ch[maxn + 11];

int main(){
	int n,m;
	cin >> n >> m;
	scanf("%s",ch + 1);
	for (int i = 2; i <= n; i++) {
		int x = ch[i - 1] - 'a';
		int y = ch[i] - 'a';
		if (x != y) cnt[(1 << x) | (1 << y)]++;
	}
	for (int j = 0; j < m; j++)
		for (int i = 3; i < (1 << m); i++)
			if (i & (1 << j)) cnt[i] += cnt[i ^ (1 << j)];
	for (int i = 1; i < (1 << m); i++) f[i] = inf;
	f[0] = 0;
	for (int i = 1; i < (1 << m); i++){ 
		int x,y; x = y = 0;
		for (int j = 0; j < m; j++) 
			if (i & (1 << j)) x += (1 << j); else y += (1 << j);
		ll add = cnt[(1 << m) - 1] - cnt[x] - cnt[y];
		for (int j = 0; j < m; j++)
			if (i & (1 << j)) f[i] = min(f[i] , f[i ^ (1 << j)] + add);
	}
	cout << f[(1 << m) - 1] << endl;
}

