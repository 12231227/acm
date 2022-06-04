#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

const int maxn = 1e6;
int has[2 * maxn + 11],sum[2 * maxn + 11],l[2 * maxn + 11],r[2 * maxn + 11];
vector <int> point;

void push(int x) {
	x *= 2;
	point.emplace_back(x - 1);
	point.emplace_back(x + 1);
	point.emplace_back(x);
}

int main(){
	int t;
	scanf("%d" , &t);
	while (t--) {
		int n;
		scanf("%d" , &n);
		point.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d %d",&l[i],&r[i]);
			push(l[i]);
			push(r[i]);
		}
		sort(all(point));
		point.erase(unique(all(point)) , point.end());
		int m = point.size();
		for (int i = 1; i <= n; i++) {
			int L = lower_bound(all(point) , l[i] * 2) - point.begin() + 1;
			int R = lower_bound(all(point) , r[i] * 2) - point.begin() + 1;
			sum[R + 1]--; sum[L]++;
		} 
		for (int i = 1; i <= m; i++) sum[i] += sum[i - 1];
		for (int i = 1; i <= m; i++)
			if (sum[i - 1] != 1 && sum[i] == 1) has[i] = has[i - 1] + 1; else has[i] = has[i - 1];
		int ans = 0;
		bool flag = false;
		for (int i = 1; i <= m; i++)
			if (sum[i] == 0) { if (flag) ans++; flag = false; } else flag = true;
		int mx = 0;
		for (int i = 1; i <= n; i++) {
			int L = lower_bound(all(point) , l[i] * 2) - point.begin() + 1;
			int R = lower_bound(all(point) , r[i] * 2) - point.begin() + 1;
			int cnt = has[R] - has[L - 1];
			if (sum[L] == 1 && sum[L - 1] == 1) cnt++;
			if (sum[R] == 1 && sum[R + 1] == 0) cnt--;
			if (sum[L] == 1 && sum[L - 1] == 0) cnt--;
			
			mx = max(mx , ans + cnt);
		}
		printf("%d\n" , mx);
		for (int i = 1; i <= m; i++) sum[i] = 0,has[i] = 0;
	} 
} 

