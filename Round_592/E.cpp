#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int maxn = 1e5;

ll a[maxn + 11];
vector <pair<ll,ll> > v;

int main(){
	int n;
	ll k;
	scanf("%d %lld",&n,&k);
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	sort(a + 1 , a + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (v.empty() || v[v.size() - 1].first != a[i]) v.pb(make_pair(a[i] , 1ll));
		else v[v.size() - 1].second++;
	}
	int l = 0; int r = (int)v.size() - 1;
	while (l < r) {
		if (v[l].second < v[r].second) {
			if ((v[l + 1].first - v[l].first) * v[l].second > k) {
				printf("%lld\n" , v[r].first - (v[l].first + k / v[l].second));
				return 0;
			}
			else {
				k -= (v[l + 1].first - v[l].first) * v[l].second;
				v[l + 1].second += v[l].second;
				l++;
			}
		} 
		else { 
			if ((v[r].first - v[r - 1].first) * v[r].second > k) { 
				printf("%lld\n" , v[r].first - v[l].first - k / v[r].second);
				return 0;
			} 
			else {
				k -= (v[r].first - v[r - 1].first) * v[r].second;
				v[r - 1].second += v[r].second;
				r--;
			}
		}
	}
	printf("0\n");
	return 0;
}
