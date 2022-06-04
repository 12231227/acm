#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;

int num[maxn + 11],r[maxn + 11],l[maxn + 11],a[maxn + 11];

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		if (l[a[i]] == 0) l[a[i]] = i;
		r[a[i]] = i;
		num[a[i]]++;
	} 
	int L,R;
	L = 1; R = 0;
	int ans = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) { 
		R = max(r[a[i]] , R);
		cnt = max(cnt , num[a[i]]);
		if (r[a[i]] == i && i == R) { 
			ans += R - L + 1 - cnt;
			cnt = 0;
			L = i + 1;
		} 
	} 
	printf("%d\n",ans);
} 

