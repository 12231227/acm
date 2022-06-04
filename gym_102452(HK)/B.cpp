#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d" , &t);
	while (t--) {
		int n;
		scanf("%d" , &n);
		for (int i = 1; i < n; i++) {
			int u,v;
			scanf("%d%d" , &u,&v);
		}
		if (n % 2 == 1) printf("Alice\n");
		else printf("Bob\n");
	} 
} 

