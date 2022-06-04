#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;
const int maxn = 2e5;

set <pair<ll,int> > s;
set <pair<ll,int> > :: iterator it;
ll sum[maxn + 11];
int a[maxn + 11],to[maxn + 11];

int main(){
	int n; scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	ll ans = 0;
	if (a[n]) to[n] = n , ans = 1; else to[n] = n - 1;
	int mn = to[n];
	s.insert(make_pair(inf , n + 1));
	s.insert(make_pair(sum[n] , n));
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] == 0) {
			to[i] = i - 1;
			mn = i - 1;
			s.insert(make_pair(sum[i] , i));
			continue;
		}
		it = s.lower_bound(make_pair(sum[i - 1] , 0));
		pair <ll,int> pi = *it;
		if (pi.first > sum[i - 1]) to[i] = mn;
		else to[i] = min(pi.second - 1 , mn);
		mn = min(mn , to[i]);
		ans += to[i] - i + 1;
		s.insert(make_pair(sum[i] , i));
	}
	printf("%lld\n" , ans);
} 

