#include <stdio.h>
using namespace std;
int main()
{
	long long h,t;
	int i,n,x;
	long long a[200005];
	scanf("%lld %d",&h,&n);
	a[0]=0;
	t=0;
	long long minn=1e12;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[i]=a[i-1]+x;
		if (minn>a[i]) minn=a[i];
		if (h+a[i]<=0 && t==0) t=i;
	}
	if (t) printf("%lld\n",t);
	else if (a[n]>=0) printf("-1\n");
	else
	{
		long long need=(-h-minn)/(a[n]);
		if (need<0) need=0;
		t=need*n;
		h+=a[n]*need;
		while (1)
		{
			if (h+minn<=0) break;
			h+=a[n]; t=t+n;
		}
		for (i=1;i<=n;i++) if (h+a[i]<=0) break;
		printf("%lld\n",t+i); 
	}
}

