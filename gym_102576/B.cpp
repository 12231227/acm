#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e6;
int a[maxn + 11];
ll f[maxn + 11];

int main(){
	int t;
	for (scanf("%d",&t);t;t--) {
		int n;
		scanf("%d",&n);
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d",&a[i]);
			f[a[i]]++;
		}
		for(int i = 0; i < 20; i++){
		    for(int j = 1; j <= maxn ; j++){
		        if (j & ( 1 << i)) f[j] += f[j ^ (1<<i)];
		    }
		}
		for (int i = 1; i <= n; i++) ans += f[a[i]];
		printf("%lld\n" , ans);
		for (int i = 1; i <= maxn; i++) f[i] = 0;
	}
} 
