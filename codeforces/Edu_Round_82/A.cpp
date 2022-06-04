#include <bits/stdc++.h>
using namespace std;

char ch[111];
int sum[111];
int main(){
	int t;
	scanf("%d" , &t);
	while (t--) {
		scanf("%s" , ch + 1);
		int n = strlen(ch + 1);
		int s = 0; int e = 0;
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1];
			if (ch[i] == '0') sum[i]++;
			if (ch[i] == '1') {
				e = i;
				if (s == 0) s = i;
			}
		}
		if (s == 0) { printf("0\n"); continue; }
		printf("%d\n" , sum[e] - sum[s - 1]);
	}
}
