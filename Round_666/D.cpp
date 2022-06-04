#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int a[105];

int main(){ 
	int t; scanf("%d",&t);
	while (t--) {
		int n; scanf("%d",&n);
		int Xor = 0;
		for (int i = 1; i <= n; i++) scanf("%d",&a[i]) , Xor ^= (a[i] % 2);
		if (Xor == 1) { printf("T\n"); continue; }
		sort(a + 1 , a + 1 + n);
		int s = 0;
		for (int i = 1; i < n; i++) s += a[i];
		if (s < a[n]) printf("T\n"); else printf("HL\n");
	}
} 