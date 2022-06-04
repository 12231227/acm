#include <bits/stdc++.h>
using namespace std;

bool vis[10000000] = {false};
int cnt = 0;
int prime[100000];

int main(){
	for (int i = 2; ; i++){
		if (!vis[i]) { prime[++cnt] = i; if (cnt >= 200) break; }
		for (int j = 1; j <= cnt; j++) {
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		} 
	} 
	for (int i = 1; i <= 200; i++) printf("%d," , prime[i]);
} 

