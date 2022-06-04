#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const int maxn = 2e5;
int st[maxn + 11][25];
int a[maxn + 11];
int ans[maxn + 11];

int Log(int n) { for (int i = 0; ; i++) if ((1 << i) > n) return i - 1; }

int query(int l,int r) {
	int j = Log(r - l + 1);
	return max(st[l][j] , st[r - (1 << j) + 1][j]);
}

int main(){
	int n;
	scanf("%d",&n);
	int maxx = 0;
	int minn = 2e9;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		maxx = max(maxx , a[i]);
		minn = min(minn , a[i]);
	}
	if (minn * 2 >= maxx) {
		for (int i = 1; i <= n; i++) printf("-1 ");
		return 0;
	}
	for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
	n *= 2;
	int lg = Log(n);
	for (int i = 1; i <= n; i++) st[i][0] = a[i];
	for (int j = 1; j <= lg; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			st[i][j] = max(st[i][j - 1] , st[i + (1 << (j - 1))][j - 1]);
	int l = 1;
	for (int i = 2; i <= n; i++){ 
		int now = 2 * a[i] + 1;
		while (query(l , i) >= now) {
			ans[l] = i - l;
			l++;
		}
	} 
	for (int i = l; i <= n / 2; i++) ans[i] = ans[1] + n / 2 - i + 1;
	for (int i = 1; i <= n / 2; i++) printf("%d ",ans[i]);
} 

