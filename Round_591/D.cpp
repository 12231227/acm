#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back

using namespace std;

const int maxn = 3e5;
vector <int> v;
int l[maxn + 11],r[maxn + 11];

int main(){
	int q;
	scanf("%d",&q);
	while (q--) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d",&x);
			v.pb(x);
			if (l[x] == 0) l[x] = i;
			r[x] = i;
		}
		sort(v.begin(),v.end());
		v.erase(unique(all(v)) , v.end());
		n = v.size();
		int cnt = 0;
		int ri = 0;
		int ans = n - 1;
		for (int i = 0; i < n; i++) {
			if (l[v[i]] > ri) { ri = r[v[i]]; cnt++; } 
			else { ans = min(ans , n - cnt); cnt = 1; ri = r[v[i]]; } 
		}
		ans = min(ans , n - cnt);
		printf("%d\n" , ans);
		for (int i = 1; i <= v[n  - 1]; i++) l[i] = r[i] = 0;
		v.clear();
	}
}

