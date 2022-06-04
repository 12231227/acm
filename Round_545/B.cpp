#include <cstdio>
using namespace std;

int a[5011],c[5011];

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&c[i]);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	int x,y,m,p;
	for (int i = 1; i <= n; i++){
		if (a[i] == 0 && c[i] == 0) x++;
		if (a[i] == 0 && c[i] == 1) y++;
		if (a[i] == 1 && c[i] == 0) m++;
		if (a[i] == 1 && c[i] == 1) p++;
	}
	
}

