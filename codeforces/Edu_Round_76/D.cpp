#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(),(x).end()

using namespace std;

const int maxn = 2e5;
int st[maxn + 11][30];
int maxx[maxn + 11],f[maxn + 11];
int p[maxn + 11],s[maxn + 11],a[maxn + 11],lg[maxn + 11]; 

int Log(int n) {
	for (int i = 1; ; i++)
		if ((1 << i) > n) return i - 1;
}

int query(int l,int r) {
	int len = r - l + 1;
	int j = lg[len];
	return max(st[l][j] , st[r - (1 << j) + 1][j]);
}

int main(){
	for (int i = 1; i <= maxn; i++) lg[i] = Log(i);
	int t;
	scanf("%d",&t);
	while (t--) {
		int n;
		scanf("%d",&n);
		int can = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d",&a[i]);
			can = max(can , a[i]);
			st[i][0] = a[i];
		}
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 1; i + (1 << j) - 1 <= n; i++)
				st[i][j] = max(st[i][j - 1] , st[i + (1 << (j - 1))][j - 1]);
		int m;
		scanf("%d",&m);
		for (int i = 1; i <= m; i++) {
			scanf("%d %d",&p[i],&s[i]);
			maxx[s[i]] = max(maxx[s[i]] , p[i]);
		} 
		for (int i = n - 1; i >= 1; i--) maxx[i] = max(maxx[i + 1] , maxx[i]);
		if (can > maxx[1]) { printf("-1\n"); for (int i = 1; i <= n; i++) maxx[i] = 0; continue; }
		deque <int> q;
		q.push_back(0);
		f[0] = 0;
		for (int i = 1; i <= n; i++) { 
			while (!q.empty() && maxx[i - q.back()] < query(q.back() + 1, i)) q.pop_back();
			f[i] = f[q.back()] + 1;
			q.push_front(i);
		}
		printf("%d\n" , f[n]);
		for (int i = 1; i <= n; i++) maxx[i] = 0;
	} 
} 

