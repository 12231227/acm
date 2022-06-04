#include <stdio.h>
using namespace std;
int main()
{
	int n,m,p,tot;
	scanf("%d %d",&n,&m);
	if (m % n!=0) printf("-1\n");
	else
	{
		p=m/n;
		tot=0;
		if (p!=1)
		{
			while (p % 2==0) p=p/2,tot++;
			while (p % 3==0) p=p/3,tot++;
		}
		if (p!=1) printf("-1\n");else printf("%d\n",tot);
	}
} 
