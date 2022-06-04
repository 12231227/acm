#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ll long long
using namespace std;

const int maxn = 2000;

vector <int> v;
int a[maxn + 11];
int sum[maxn + 11][maxn + 11];

int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		int n;
		scanf("%d",&n);
		v.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d",&a[i]);
			v.pb(a[i]);
		}
		sort(all(v));
		v.erase(unique(all(v)) , v.end());
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= v.size(); j++)
				sum[j][i] = sum[j][i - 1];
			int ind = lower_bound(all(v) , a[i]) - v.begin() + 1;
			sum[ind][i]++;
		} 
		ll ans = 0;
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				int val = 2 * a[j] - a[i];
				if (val > v[v.size() - 1]) continue;
				int ind = lower_bound(all(v) , val) - v.begin();
				if (v[ind] != val) continue;
				ind++;
				ans += sum[ind][n] - sum[ind][j];
			}
		printf("%lld\n" , ans);
	} 
} 
