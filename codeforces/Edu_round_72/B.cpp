#include <cstdio>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		int n,x;
		scanf("%d %d",&n,&x);
		int dm = 0;
		int m = 0;
		for (int i = 1; i <= n; i++){
			int u,v;
			scanf("%d %d",&u,&v);
			if (u - v > m) m = u - v;
			if (u > dm) dm = u;
		}
		x -= dm;
		if (x <= 0) printf("1\n");
		else if (m == 0) printf("-1\n");
		else {
			printf("%d\n",x / m + (x % m != 0) + 1);
		}
	}
}

