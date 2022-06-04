#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5;

ll x,y,a,b;
ll k;
ll p[maxn + 11];
ll sum[maxn + 11];

ll gcd(ll a,ll b) { return b == 0 ? a : gcd(b , a % b); }

bool cmp(ll a,ll b) { return a > b; }

bool check(ll n) {
	ll lcm = a * b / gcd(a , b);
	ll num = n / lcm;
	ll numa = n / a - num;
	ll numb = n / b - num;
	ll cnt = sum[num] / 100 * (x + y);
	if (x > y) {
		cnt += (sum[num + numa] - sum[num]) / 100 * x;
		cnt += (sum[num + numa + numb] - sum[num + numa]) / 100 * y;
	}
	else {
		cnt += (sum[num + numb] - sum[num]) / 100 * y;
		cnt += (sum[num + numb + numa] - sum[num + numb]) / 100 * x;
	}
	return (cnt >= k);
}

int main(){
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> p[i];
		sort(p + 1, p + 1 + n , cmp);
		memset(sum,0,sizeof(sum));
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + p[i];
		cin >> x >> a;
		cin >> y >> b;
		cin >> k;
		int l = 1; int r = n;
		int ans = -1;
		while (l <= r) { 
			int mid = (l + r) / 2;
			if (check(mid)) { ans = mid; r = mid - 1; } 
			else l = mid + 1;
		} 
		cout << ans << endl;
	} 
} 

