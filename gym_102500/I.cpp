#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int a[maxn + 11],b[maxn + 11];

int main(){
	int n;
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) { scanf("%d" , &a[i]); b[i] = a[i]; }
	sort(b + 1 , b + 1 + n);
	int l = n;
	for (int i = 1; i <= n; i++) if (a[i] != b[i]) { l = i; break; }
	int r = 1;
	for (int i = n; i >= 1; i--) if (a[i] != b[i]) { r = i; break; }
	if (l > r) {
		printf("1 1\n");
		return 0;
	}
	int ansl = l; int ansr = r;
	while (l < r) {
		swap(a[l] , a[r]);
		l++; r--;
	}
	bool flag = true;
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i]) { flag = false; break; }
	if (flag) printf("%d %d\n" , ansl , ansr);
	else printf("impossible\n");
} 

