#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

const int maxn = 1e6;
int a[maxn + 11];
vector <int> v;
int vis[maxn + 11];

int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		int n,k,d;
		scanf("%d %d %d",&n,&k,&d);
		v.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d",&a[i]);
			v.push_back(a[i]);
		}
		sort(all(v));
		v.erase(unique(all(v)) , v.end());
		int cnt = 0;
		for (int i = 1; i <= d; i++) {
			int ind = lower_bound(all(v) , a[i]) - v.begin();
			if (vis[ind] == 0) cnt++;
			vis[ind]++;
		}
		int ans = cnt;
		for (int i = d + 1; i <= n; i++) {
			int ind = lower_bound(all(v) , a[i - d]) - v.begin();
			vis[ind]--;
			if (vis[ind] == 0) cnt--;
			ind = lower_bound(all(v) , a[i]) - v.begin();
			if (vis[ind] == 0) cnt++;
			vis[ind]++;
			ans = min(ans , cnt);
		}
		printf("%d\n",ans);
		for (int i = 0; i < v.size(); i++) vis[i] = 0;
	}
} 
