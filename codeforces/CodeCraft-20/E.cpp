#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e16;
const int maxn = 1e5;
ll f[130];
struct person{
	int aud;
	int pos[10];
}per[maxn + 11];

int main(){
	int n,p,k;
	scanf("%d %d %d",&n,&p,&k);
	for (int i = 1; i <= n; i++) scanf("%d",&per[i].aud);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= p; j++) scanf("%d",&per[i].pos[j]);
	sort(per + 1 , per + 1 + n ,[&](person a,person b) { return a.aud > b.aud; });
	for (int i = 1; i < (1 << p); i++) f[i] = -inf;
	for (int i = 1; i <= n; i++)
		for (int j = (1 << p) - 1; j >= 0; j--) {
			if (i - __builtin_popcount(j) <= k) f[j] += per[i].aud;
			for (int o = 0; o < p; o++)
				if (j & (1 << o)) f[j] = max(f[j] , f[j ^ (1 << o)] + per[i].pos[o + 1]);
		}
	printf("%lld\n" , f[(1 << p) - 1]);
} 

