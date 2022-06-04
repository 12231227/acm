#include <bits/stdc++.h>
using namespace std;
int main(){ 
	int t;
	scanf("%d",&t);
	while (t--) {
		int n;
		scanf("%d",&n);
		long long odd1,odd2,even1,even2;
		odd1 = odd2 = even1 = even2 = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d",&x);
			if (x % 2 == 1) odd1++; else even1++;
		}
		int m;
		scanf("%d",&m);
		for (int i = 1; i <= m; i++) {
			int x;
			scanf("%d",&x);
			if (x % 2 == 1) odd2++; else even2++;
		}
		cout << odd1 * odd2 + even1 * even2 << endl;
	}
} 

