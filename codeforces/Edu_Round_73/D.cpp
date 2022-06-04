#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

const int maxn = 3e5;
const ll inf = 2e18;

ll f[maxn + 11][3];
ll a[maxn + 11],b[maxn + 11];

int main(){
	int q;
	scanf("%d",&q);
	while (q--) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++)
		 scanf("%lld %lld",&a[i],&b[i]);
		f[1][0] = 0; f[1][1] = b[1]; f[1][2] = b[1] * 2;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= 2; j++){
			 f[i][j] = inf;
			 for (int k = 0; k <= 2; k++)
			  if (a[i] + j != a[i - 1] + k) f[i][j] = min(f[i][j] , f[i - 1][k] + b[i] * j);
			}
		}
		printf("%lld\n",min(min(f[n][0] , f[n][1]) , f[n][2]));
	}
}

