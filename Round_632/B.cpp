#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int a[maxn + 11],b[maxn + 11];

int main(){
	int _;
	for (scanf("%d",&_);_;_--) {
		int n; scanf("%d" , &n);
		int A = 0,B = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d",&a[i]);
			if (a[i] > 0) A++;
			else if (a[i] < 0) B++;
		}
		for (int i = 1; i <= n; i++) scanf("%d",&b[i]);
		bool flag = true;
		for (int i = n; i >= 1; i--) {
			if (a[i] > 0) A--;
			else if (a[i] < 0) B--;
			if (a[i] == b[i]) continue;
			if (a[i] > b[i] && B) continue;
			if (a[i] < b[i] && A) continue;
			flag = false; break;
		}
		if (flag) puts("YES"); else puts("NO");
	}
} 

