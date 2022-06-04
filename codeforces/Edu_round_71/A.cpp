#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		int b,p,f;
		scanf("%d %d %d",&b,&p,&f);
		int h,c;
		scanf("%d %d",&h,&c);
		if (h < c) { swap(h,c); swap(p,f); }
		b /= 2;
		int ans = 0;
		if (b > p) ans = h * p + min(b - p , f) * c;
		else ans = h * b;
		printf("%d\n",ans);
	}
}

