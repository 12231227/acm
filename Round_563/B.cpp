#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn  = 1e5 +11;
int a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	bool flag = false;
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	int now = a[1] % 2;
	for (int i = 2 ;i <= n; i++) if (a[i] % 2 != now) { flag = true; break; }
	if (flag){
		sort(a+1,a+1+n);
		for (int i = 1; i < n; i++) printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
	else{
		for (int i = 1; i < n; i++) printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
}
