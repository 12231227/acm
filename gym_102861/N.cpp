#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 2e6;
double p[maxn + 11],sp[maxn + 11];
double f[maxn + 11],s[maxn + 11];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,a,b; cin >> n >> a >> b;
	double per = 1.0 / (b - a + 1);
	double ans = 0;
	double ss = 0;
	if (a) { 
		for (int i = a; i <= n; i++) { 
			int r = i - a;
			double sum = s[i - a];
			int l = 0;
			if (i - b > 0) sum -= s[i - b - 1] ,  l = i - b;
			f[i] = 1.0 * sum * per + 1;
			s[i] = s[i - 1] + f[i];
		} 
		printf("%.8lf\n" , f[n]);
	} 
	else { 
		per = 1.0 / (b - a);
		double add = 1.0 * (b - a + 1) / (b - a);
		a = 1;
		for (int i = 1; i <= n; i++) { 
			int r = i - a;
			double sum = s[i - a];
			double sump = sp[i - a];
			int l = 0;
			if (i - b > 0) sum -= s[i - b - 1] , sump -= sp[i - b - 1] , l = i - b;
			f[i] = 1.0 * sum * per + add;
			p[i] = sump * per;
			s[i] = s[i - 1] + f[i];
			sp[i] = sp[i - 1] + p[i];
		} 
		for (int i = n + 1; i < n + b; i++) { 
			int r = min(i - a , n - 1);
			double sum = s[r];
			double sump = sp[r];
			int l = 0;
			if (i - b > 0) sum -= s[i - b - 1] , sump -= sp[i - b - 1] , l = i - b;
			f[i] = 1.0 * sum * per + add;
			p[i] = sump * per;
			s[i] = s[i - 1] + f[i];
			sp[i] = sp[i - 1] + p[i];
		} 
		printf("%.8lf\n" , f[n]);
	} 
} 