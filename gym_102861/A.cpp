#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e6;
double s[maxn + 11],f[maxn + 11];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,a,b; cin >> n >> a >> b;
	if (a) {
		for (int i = 1; i <= a; i++) f[i] = 1 , s[i] = i;
		for (int i = a + 1; i <= n; i++) {
			f[i] = (s[i - a] - s[max(i - b - 1 , 0)]) / (b - a + 1) + 1;
			s[i] = s[i - 1] + f[i];
		}
		printf("%.8lf\n" , f[n]);
	} 
	else {
		double x = 1.0 * (b + 1) / b;
		for (int i = 1; i <= n; i++) {
			f[i] = (s[i - 1] - s[max(i - b - 1 , 0)]) / b + x;
			s[i] = s[i - 1] + f[i];
		}
		printf("%.8lf\n" , f[n]);
	}
} 
