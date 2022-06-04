#include <cstdio>
#define ll long long
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		int n,m;
		scanf("%d %d",&n,&m);
		ll res1 = 0;
		ll res2 = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d",&x);
		}
		for (int i = 1; i <= m; i++) {
			int x;
			scanf("%d",&x);
		} 
		if (n <= m) printf("Yes\n");
		else printf("No\n");
	} 
} 

