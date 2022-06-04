#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
char ch[maxn + 11];

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	scanf("%s",ch + 1);
	if (n == 1 && k > 0) { printf("0\n"); return 0; } 
	if (k != 0 && ch[1] != '1') { k--; ch[1] = '1'; } 
	for (int i = 2; i <= n; i++) {
		if (k == 0) break;
		if (ch[i] != '0') { k--; ch[i] = '0'; } 
	} 
	for (int i = 1; i <= n; i++) printf("%c",ch[i]);
	printf("\n");
	return 0;
} 

