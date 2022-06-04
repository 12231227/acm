#include <bits/stdc++.h>
using namespace std;

int a[1111];

int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	for (int i = 1; i <= n; i++) scanf("%d" , &a[i]);
	int cnt = 0;
	a[0] = a[1];
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] - a[i - 1] <= x) cnt++;
		else cnt = 1;
		ans = max(ans , cnt);
	}
	printf("%d\n" , ans);
} 

