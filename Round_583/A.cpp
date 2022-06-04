#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n,d,e;
	scanf("%d %d %d",&n,&d,&e);
	e *= 5;
	int ans = n;
	for (int i = 0; e * i <= n; i++)
		ans = min(ans , (n - e * i) % d);
	printf("%d\n" , ans);
	return 0;
} 

