#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 2e5;
int p[maxn + 11];
 
int main(){
	int q;
	cin >> q;
	while (q--) {
		int h,n;
		cin >> h >> n;
		for (int i = 1; i <= n; i++) cin >> p[i];
		p[n + 1] = 0;
		int ans = 0;
		int now = p[1];
		int i = 2;
		while (i <= n){ 
			if (now - p[i] == 1) { 
				if (p[i + 1] + 1 == p[i]) { 
					now = p[i + 1];
					i += 2;
				}
				else { 
					i++;
					now = now - 2;
					ans++;
				}
			}
			else {
				now = p[i] + 1;
			} 
		}
		printf("%d\n"  , ans);
	}
}

