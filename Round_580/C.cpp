#include <cstdio>
using namespace std;

const int maxn = 1e5;

int a[2 * maxn + 11];

int main(){
	int n;
	scanf("%d",&n);
	if (n % 2 == 0) printf("NO\n");
	else {
		printf("YES\n");
		a[1] = 1; a[n + 1] = 2;
		for (int i = 2; i <= n; i++){
			if (i % 2 == 0) {
				a[i] = i * 2;
				a[i + n] = i * 2 - 1;
			}
			else{
				a[i] = i * 2 - 1;
				a[i +  n] = i * 2;
			}
		}
		for (int i = 1; i <= 2 * n; i++)
		 printf("%d%s",a[i],i == 2 * n ? "\n":" ");
	}
}

