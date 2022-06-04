#include <bits/stdc++.h>
using namespace std;

const int inf = 1e4;
int a[5999];
pair <int,int> per[5999];

int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		int n,m;
		scanf("%d %d",&n,&m);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d",&a[i]);
			per[i] = make_pair(a[i] , i);
			ans += 2 * a[i];
		}
		if (n == 2 || m < n) { printf("-1\n"); continue; }
		sort(per + 1 , per + 1 + n);
		ans += (per[1].first + per[2].first) * (m - n);
		printf("%d\n" , ans);
		for (int i = 1; i < n; i++) printf("%d %d\n" , i , i + 1);
		printf("%d 1\n" , n);
		for (int i = 1; i <= m - n; i++) printf("%d %d\n" , per[1].second , per[2].second);
	}
}

