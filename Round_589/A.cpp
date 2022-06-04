#include <bits/stdc++.h>
using namespace std;
int main(){
	int l,r;
	scanf("%d %d",&l,&r);
	for (int x = l; x <= r; x++){
		bool vis[10] = {false};
		int val = x;
		bool can = true;
		while (val) {
			if (vis[val % 10]) { can = false; break; }
			vis[val % 10] = true;
			val /= 10;
		}
		if (can) { printf("%d\n" ,x); return 0; }
	}
	printf("-1\n");
	return 0;
}
