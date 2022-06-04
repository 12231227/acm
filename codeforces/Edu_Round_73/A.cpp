#include <bits/stdc++.h>
using namespace std;

int num[1000];

int main(){
	int q;
	scanf("%d",&q);
	while (q--) {
		int n;
		scanf("%d",&n);
		bool can = true;
		memset(num , 0 ,sizeof(num));
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d",&x);
			for (int j = 0; j <= 29; j++)
			 if (x == (1 << j)) num[j]++;
		}
		for (int i = 0; i <= 10; i++)
		 num[i + 1] += num[i] / 2;
		if (num[11]) printf("YES\n"); else printf("NO\n");
	} 
} 

