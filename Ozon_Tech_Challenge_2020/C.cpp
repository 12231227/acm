#include <bits/stdc++.h>
using namespace std;

int a[200011];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	if (n > m) { printf("0\n"); return 0; }
	int ans = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ans = ans * (abs(a[i] - a[j]) % m) % m;
	printf("%d\n" , ans);
}

