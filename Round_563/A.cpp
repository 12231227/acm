#include <cstdio>
#include <algorithm>
using namespace std;

int a[2111];

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1 ;i <= 2*n; i++) scanf("%d",&a[i]);
	bool flag = false;
	sort(a+1,a+1+2*n);
	for (int i = 2 ;i <= 2*n; i++) if (a[i] != a[1]) { flag = true; break ;}
	if (!flag) printf("-1\n");
	else{
		for (int i = 1 ; i < 2 * n; i++) printf("%d ",a[i]);
		printf("%d\n",a[2 * n]);
	}
} 
