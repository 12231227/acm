#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e5;
int fac[maxn + 11],lg[maxn + 11];
ll p[maxn + 11];
pair <ll , int> s[maxn + 11];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n = 1e5;
	fac[0] = 1;
	for (int i = 1; ; i++) {
		fac[i] = fac[i - 1] * 2;
		if (fac[i] > n) break;
	} 
	for (int i = 1; i <= n; i++) {
		for (int j = 0; ; j ++)
			if (fac[j] > i) { lg[i] = j - 1; break; }
	}
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	sort(p + 1 , p + 1 + n , [&](ll a,ll b) { return a > b; });
	ll ans = 0;
	if (p[2] != p[3]) {
		ans = p[2] - p[3];
		for (int i = 3; i <= n; i++) p[i] += ans;
	}
	if (p[1] == p[2]) { printf("%lld\n" , ans); return 0; }
	int cnt = 0;
	ll last = p[2];
	int num = 1;
	for (int i = 3; i <= n; i++) {
		if (p[i] == last) num++;
		else { s[++cnt] = make_pair(last , num); last = p[i]; num = 1; }
	} 
	s[++cnt] = make_pair(last , num);
	int res = s[1].second;
	ll now = p[2];
	for (int i = 2; i <= cnt; i++) { 
		ll ned = s[i - 1].first - s[i].first;
		if (ned * lg[res] + now >= p[1]) {
			ans += (p[1] - now) / lg[res] * (lg[res] + 1) + (p[1] - now) - (p[1] - now) / lg[res] * lg[res];
			now = p[1];
			break;
		}
		now += ned * lg[res];
		ans += ned * (lg[res] + 1);
		res += s[i].second;
	} 
	ans += (p[1] - now) / lg[res] * (lg[res] + 1) + (p[1] - now) - (p[1] - now) / lg[res] * lg[res];
	printf("%lld\n" , ans);
} 

