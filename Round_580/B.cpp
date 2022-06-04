#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

const int maxn = 1e5;

ll a[maxn + 11],f[maxn + 11][2];

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	f[0][1] = 1e10;
	for (int i = 1; i <= n; i++){
	 f[i][0] = min(f[i - 1][0] + abs(a[i] - 1) , f[i - 1][1] + abs(a[i] + 1));
	 f[i][1] = min(f[i - 1][0] + abs(a[i] + 1) , f[i - 1][1] + abs(a[i] - 1));
	}
	printf("%lld\n",f[n][0]);
}
