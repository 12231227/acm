#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 2e5;
int c[maxn + 11];

int main(){ 
	int n; scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&c[i]);
	sort(c + 1 , c + 1 + n);
	double ans = 1;
	for (int i = 1; i <= n; i++) {
		if (c[i] > i) { ans = -1; break; }
		ans = min(ans , 1.0 * c[i] / i);
	}
	printf("%.8lf\n" , ans);
} 