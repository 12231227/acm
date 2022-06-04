#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;

const int maxn = 4000;
const ll inf = 1e15;

vector <int> v[maxn + 11];
ll k[maxn + 11],c[maxn + 11],x[maxn + 11],y[maxn + 11];
ll p[maxn + 11];
vector <int> col;
vector <pair<int,int> > path;

ll calc(int i,int j) { 
	return (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
}

signed main(){
	int n;
	scanf("%lld",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld",&x[i],&y[i]);
	} 
	for (int i = 1; i <= n; i++) scanf("%lld",&c[i]);
	for (int i = 1; i <= n; i++) scanf("%lld",&k[i]);
	int has = 1;
	v[1].pb(1);
	p[1] = c[1];
	for (int i = 2; i <= n; i++) { 
		ll minn = inf;
		int ind = 0;
		for (int j = 1; j <= has; j++){ 
			ll m = inf;
			for (int k = 0; k < v[j].size(); k++) 
				m = min(m , calc(i , v[j][k]));
			if (min(c[i] , p[j]) - p[j] + m < minn) { minn = min(c[i] , p[j]) - p[j] + m; ind = j; } 
		} 
		if (ind != 0 && minn < c[i]) { p[ind] = min(p[ind] , c[i]); v[ind].pb(i); } 
		else { v[++has].pb(i); p[has] = c[i]; } 
	} 
	ll ans = 0;
	vector <pair<pair<ll,int> , int> > vec;
	for (int i = 1; i <= has; i++) { 
		ll minn = inf;
		int ind;
		for (int j = 0; j < v[i].size(); j++) 
			if (c[v[i][j]] < minn) { 
				minn = c[v[i][j]];
				ind = v[i][j];
			}
		col.pb(ind);
		ans += minn;
		vec.clear();
		for (int j = 0; j < v[i].size(); j++)
			for (int k = j + 1; k < v[i].size(); k++) 
				vec.pb(make_pair(make_pair(calc(v[i][j] , v[i][k]) , v[i][j]) , v[i][k]));
		sort(all(vec));
		for (int j = 0; j < v[i].size() - 1; j++) 
			ans += vec[j].first.first;
		for (int j = 0; j < v[i].size() - 1; j++) 
			path.pb(make_pair(vec[j].first.second , vec[j].second));
	} 
	printf("%lld\n" , ans);
	printf("%d\n" , col.size());
	for (int i = 0; i < col.size();i++) printf("%lld ",col[i]); printf("\n");
	printf("%d\n" , path.size());
	for (int i = 0; i < path.size();i++) printf("%lld %lld\n",path[i].first , path[i].second);
} 

