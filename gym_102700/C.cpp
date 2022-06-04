#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int mol = 1e9 + 7;
const int maxn = 5e6;
int fac[maxn + 11],f[maxn + 11];

int add(int a,int b) { a += b; if (a >= mol) a -= mol; return a; }
int sub(int a,int b) { a -= b; if (a < 0) a += mol; return a; }

int main(){ 
	int a,k; scanf("%d %d",&a,&k);
	fac[0] = 1;
	for (int i = 1; i <= k; i++) fac[i] = 1ll * fac[i - 1] * a % mol;
	for (int i = 1; i <= k; i++) {
		f[i] = add(f[i] , fac[i]);
		for (int j = i * 2; j <= k; j += i) f[j] = sub(f[j] , f[i]);
	}
	int ans = 0;
	for (int i = 1; i <= k; i++) ans = add(ans , f[i]);
	printf("%d\n" , ans);
} 
