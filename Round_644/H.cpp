#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	bin[0] = 1;
	for (int i = 1; i <= 60; i++) bin[i] = bin[i - 1] * 2;
	for (scanf("%d" , &t); t; t--) {
		int n,m;
		scanf("%d %d",&n,&m);
		ll ans = (bin[m] - 1) / 2;
		for (int i = 1; i <= n; i++) {
			scanf("%s" , ch + 1);
			ll val = 0;
			int pos = 1;
			for (int i = m; i >= 1; i-- , pos++) val += bin[i] * (ch[pos] - '0');
			if (val )
		}
	}
}