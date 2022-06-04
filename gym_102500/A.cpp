#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int maxn = 3e5;
 
ll sum[maxn + 11],fix[maxn + 11];
int cnt[maxn + 11],sc[maxn + 11];
 
int main(){
	int n,w;
	scanf("%d %d",&n,&w);
	for (int i = 1; i <= n; i++) fix[i] = w;
	cnt[0] = n;
	for (int i = w; i >= 1; i--) {
		int k; scanf("%d",&k);
		while (k--) {
			int x;
			scanf("%d",&x);
			fix[x] += sum[sc[x]] - sum[sc[x] + 1];
			sum[sc[x]] += i;
			cnt[sc[x]]--; sc[x]++;
			fix[x] -= 1ll * i * cnt[sc[x]];
			cnt[sc[x]]++;
		} 
	} 
	for (int i = 1; i <= n; i++)
		printf("%.8lf\n" , (double)(fix[i] + sum[sc[i]]) / w);
} 

