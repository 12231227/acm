#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	scanf("%d",&q);
	while (q--) {
		int c,m,x;
		scanf("%d %d %d",&c,&m,&x);
		if (c > m) swap(c , m);
		x += m - c;
		if (x >= c) printf("%d\n",c);
		else {
			if ((c - x) % 3 == 2)  printf("%d\n", x + (c - x) / 3 * 2 + 1);
			else  printf("%d\n", x + (c - x) / 3 * 2);
		}
	}
}

