#include <bits/stdc++.h>
using namespace std;

bool vis[1000011] = {false};

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		char ch[111];
		scanf("%s" , ch + 1);
		if (ch[1] == '-') continue;
		int m = strlen(ch + 1);
		if (m > 7) continue;
		int ten = 1; int x = 0;
		for (int j = m; j >= 1; j--) {
			x += (ch[j] - '0') * ten;
			ten *= 10;
		}
		if (x <= n) vis[x] = true;
	} 
	for (int i = 0; ; i++)
		if (!vis[i]) { printf("%d\n" , i); break; }
} 

