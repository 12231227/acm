#include <bits/stdc++.h>
using namespace std;

int n;

int DP(int x) {
	int pre = 0;
	char c = ch[1]; ch[1] = x ? 'R' : 'L';
	if (c != ch[1]) pre++;
	memset(f , 0x3f3f3f , sizeof(f));
	for (int i = 2; i <= n; i++) {
		
	}
	ch[1] = c;
} 

int main(){ 
	int t; scanf("%d",&t);
	while (t--) { 
		scanf("%d",&n);
		scanf("%s" , ch + 1);
		printf("%d\n" , min(DP(0) , DP(1)));
	} 
} 
