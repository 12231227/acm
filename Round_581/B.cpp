#include <cstdio>
#define ll long long
using namespace std;
int main(){
	int n,l,r;
	scanf("%d %d %d",&n,&l,&r);
	ll minn = n - l + 1;
	ll now = 1;
	for (int i = 1; i < l; i++) { now *= 2; minn += now; }
	ll maxx = 0;
	now = 1;
	for (int i = 1; i <= r; i++) { maxx += now; now *= 2; }
	now /= 2;
	for (int i = r + 1; i <= n; i++) maxx += now;
	printf("%lld %lld\n",minn,maxx);
}

