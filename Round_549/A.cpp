#include <cstdio>
using namespace std;

int a[200100];

int main()
{
	int n,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	int x=0,y=0;
	for (i=n;i>=1;i--)
	 if (x && y) break;
	 else{
	 	if (a[i] && !y) y=i;
	 	if (!a[i] && !x) x=i;
	 }
	if (x<y) printf("%d\n",x);
	else printf("%d\n",y);
}
