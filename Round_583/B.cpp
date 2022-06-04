#include <cstdio>
using namespace std;
int main(){
	int b,g,n;
	scanf("%d %d %d",&b,&g,&n);
	int ans = 0;
	for (int i = 0; i <= n; i++)
		if (i <= b && n - i <= g) ans++;
	printf("%d\n",ans);
} 

