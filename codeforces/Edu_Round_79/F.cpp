#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int inf = 1e7;
int n,k,L;
int sum[maxn + 11];
char ch[maxn + 11];
pair <int,int> f[maxn + 11];

pair <int,int> check(int x) { 
	f[0] = {0 , 0};
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if (i >= L) f[i] = max(f[i] , {f[i - L].first + sum[i] - sum[i - L] - x , f[i - L].second + 1});
		else f[i] = max(f[i] , {sum[i] - x, 1});
	}
	return f[n];
} 

int main(){
	scanf("%d %d %d",&n,&k,&L);
	scanf("%s" , ch + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + ((ch[i] <= 'z' && ch[i] >= 'a') ? 1 : 0);
	int l = 0; int r = n; int per = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		pair <int,int> pi = check(mid);
		if (pi.second >= k)
		{ per = mid; l = mid + 1; } else r = mid - 1;
	}
	int ans = check(per).first + per * k;
	ans = sum[n] - ans;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + ((ch[i] <= 'Z' && ch[i] >= 'A') ? 1 : 0);
	l = 0; r = n; per = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid).second >= k) { per = mid; l = mid + 1; } else r = mid - 1;
	}
	ans = min(ans , sum[n] - check(per).first - per * k);
	printf("%d\n" , ans);
} 

