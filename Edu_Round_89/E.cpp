#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 998244353;
const int maxn = 2e5;
int a[maxn + 11],b[maxn + 11];
int pos[maxn + 11],posl[maxn + 11],posr[maxn + 11];

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	for (int i = 1; i <= m; i++) scanf("%d",&b[i]);
	stack <int> s;
	s.push(0);
	for (int i = 1; i <= n; i++) {
		while (a[s.top()] >= a[i]) s.pop();
		posl[i] = s.top();
		s.push(i);
	}
	while (!s.empty()) s.pop();
	s.push(n + 1);
	for (int i = n; i >= 1; i--) {
		while (a[s.top()] >= a[i]) s.pop();
		posr[i] = s.top();
		s.push(i);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] > b[m]) continue;
		int ind = lower_bound(b + 1 , b + 1 + m , a[i]) - b;
		if (b[ind] == a[i]) pos[ind] = i;
	}
	bool flag = true;
	for (int i = 1; i < m; i++)
		if (pos[i + 1] < pos[i]) { flag = false; break; }
	for (int i = 1; i <= m; i++)
		if (posr[pos[i]] <= n)  { flag = false; break; }
	if (!flag || posl[pos[1]]) { puts("0"); return 0; }
	ll ans = 1;
	for (int i = 2; i <= m; i++) ans = ans * (pos[i] - posl[pos[i]]) % mol;
	printf("%lld\n" , ans);
} 
