#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 8000;
ll a[maxn + 11],b[maxn + 11];
vector<pair<ll , ll> > v,o;
pair <ll ,ll> p[maxn + 11];
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	for (int i = 1; i <= n; i++) scanf("%lld",&b[i]);
	if (n == 1) { printf("0\n"); return 0; }
	for (int i = 1; i <= n; i++) p[i] = make_pair(a[i] , b[i]);
	sort(p + 1, p + 1 + n);
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		if (i == 1 && p[i].first != p[i + 1].first) v.push_back(p[i]);
		else if (i == n && p[i].first != p[i - 1].first) v.push_back(p[i]);
		else if (p[i].first != p[i + 1].first && p[i].first != p[i - 1].first) v.push_back(p[i]);
		else {
			ans += p[i].second;
			o.push_back(p[i]);
		} 
	} 
	for (int i = 0; i < v.size(); i++)
	 for (int j = 0; j < o.size(); j++) {
	 	if ((v[i].first & o[j].first) == v[i].first) {
	 		ans += v[i].second;
	 		break;
		 }
	 }
	printf("%lld\n",ans);
} 

