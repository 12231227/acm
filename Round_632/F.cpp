#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5;
int ans[maxn + 11];
bool vis[maxn + 11];

int main(){
	int n; scanf("%d",&n);
	int r = n;
	for (int g = n / 2; g >= 1; g--) {
		int cnt = 0;
		for (int i = g; i <= n; i += g){
			if (!vis[i]) cnt++;
			if (i != g) vis[i] = true;
		}
		for (int i = r - cnt + 2; i <= r; i++) ans[i] = g;
		r = r - cnt + 1;
	}
	for (int i = 2; i <= n; i++) printf("%d " , ans[i]);
} 
