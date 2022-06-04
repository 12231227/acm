#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;
const int maxn = 1e3;
ll a[maxn + 11];
ll m[maxn + 11][maxn + 11];
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	 for (int j = 1; j <= n; j++) scanf("%lld",&m[i][j]);
	ll A1 = m[1][2]; ll A2 = m[1][3]; ll A3 = m[2][3];
	a[3] = sqrt(A2 * A3 / A1);
	for (int i = 1; i <= n; i++) if (i != 3) a[i] = m[3][i] / a[3];
	for (int i = 1; i <= n; i++) printf("%lld%s",a[i],i==n?"\n":" ");
} 

