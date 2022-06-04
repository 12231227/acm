#include <bits/stdc++.h>
using namespace std;
int p[11] = {2,3,5,7,11,13,17,19,23,29,31};

int col[11111];
int cnt[20],num[20];
int main(){
	int _;
	for (scanf("%d",&_);_;_--) {
		int n; scanf("%d",&n);
		for (int i = 0; i < 11; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d",&x);
			for (int j = 0; j < 11; j++)
				if (x % p[j] == 0) { cnt[j]++; col[i] = j; break; }
		}
		int ans = 0;
		for (int i = 0; i < 11; i++) {
			if (cnt[i]) {
				ans++;
				num[i] = ans;
			}
		}
		printf("%d\n" , ans);
		for (int i = 1; i <= n; i++) printf("%d%s" , num[col[i]] , i == n ? "\n" : " ");
	}
}
