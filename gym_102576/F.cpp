#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt[20][400],f[20][400];
pair <ll,ll> dp[400];
ll sum1[400],sum2[400],res[400],sum[400];
int p[50];

ll gcd(ll a,ll b) { return b ? gcd(b , a % b) : a; }

struct Frac{
    ll a,b;
    Frac(ll _a=0,ll _b=1){
        a=_a; b=_b;
    }
}out[400];
Frac operator + (Frac p,Frac q){
    Frac rs(p.a*q.b+p.b*q.a,p.b*q.b); return rs;
}

bool operator <= (Frac p,Frac q){
    p.a*=q.b; q.a*=p.b; return p.a<=q.a;
}

void init() {
	for (int i = 2; i <= 16; i++) {
		for (int j = 0; j <= i; j++)
			for (int k = 0; k <= i * (i - 1) / 2; k++) f[j][k] = 0;
		for (int j = 0; j <= i * (i - 1) / 2; j++) sum[j] = 0;
		for (int j = 1; j <= i; j++) {
			f[j][0] = 1;
			for (int k = 1; k <= j * (j - 1) / 2; k++){
				if (k - (j - 1) > 0) f[j][k] = sum[k] - sum[k - (j - 1) - 1];
				else f[j][k] = sum[k];
			}
			sum[0] = 1;
			for (int k = 1; k <= j * (j - 1) / 2; k++) sum[k] = sum[k - 1] + f[j][k];
			for (int k = j * (j - 1) / 2 + 1; k <= (i - 1) * i / 2; k++) sum[k] = sum[k - 1];
		}
		for (int j = 0; j <= i * (i - 1) / 2; j++) cnt[i][j] = f[i][j];
	}
}

void solve() {
	int n,a,b,c,d;
	scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
	int m = n * (n - 1) / 2;
	dp[0] = {0 , 0};
	for (int i = 1; i <= m; i++) dp[i] = {min(1ll * a * i , 0ll + b + 1ll * (m - i) * a) , i};
	sort(dp + 1 , dp + 1 + m);
	res[0] = 1;
	for (int i = 0; i <= m; i++) res[i] = cnt[n][dp[i].second];
	for (int i = 1; i <= m; i++) sum1[i] = sum1[i - 1] + res[i] * dp[i].first;
	sum2[0] = res[0];
	for (int i = 1; i <= m; i++) sum2[i] = sum2[i - 1] + res[i];
	ll fac = 1;
	for (int i = 2; i <= n; i++) fac *= i;
	Frac ans;
	int ind = m;
	for (int j = 0; j < m; j++) {
		ll S = sum1[j];
		ll M = sum2[m] - sum2[j];
		Frac x = Frac{S + M * c , fac - M} + Frac{c , 1};
		if (Frac{dp[j].first , 1} <= x && x <= Frac(dp[j + 1].first , 1)) {
			ans = x;
			ind = j;
			break;
		}
	}
	ll g = gcd(ans.a , ans.b);
	ans.a /= g; ans.b /= g;
	for (int i = 0; i <= ind; i++) out[dp[i].second] = Frac{dp[i].first , 1};
	for (int i = ind + 1; i <= m; i++) out[dp[i].second] = ans;
	while (d--) {
		for (int i = 1; i <= n; i++) scanf("%d",&p[i]);
		int l = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (p[j] < p[i]) l++;
		printf("%lld/%lld\n" , out[l].a , out[l].b);
	}
}

int main(){
	init();
	int t;
	for (scanf("%d",&t);t;t--) solve();
}

