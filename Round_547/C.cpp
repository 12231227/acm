#include <stdio.h>
#include <algorithm> 
using namespace std;
int a[200005],b[200005],c[200005];

int main()
{
	int n,i,minn,x;
	scanf("%d",&n);
	minn=n;
	b[0]=0;
	for (i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]+=a[i]+b[i-1];
	}
	for (i=1;i<n;i++)
	 if (b[i]<minn) minn=b[i];
	if (minn==1) x=1;
	else x=1-minn;
	c[1]=x;
	for (i=1;i<n;i++)
	 c[i+1]=x+b[i];
	sort(c+1,c+1+n);
	bool can=true;
	for (i=1;i<=n;i++)
	 if (c[i]!=i) { can=false ;break; }
	if (!can) printf("-1\n");
	else
	{
	printf("%d ",x);
	for (i=1;i<n-1;i++) printf("%d ",x+b[i]);
	printf("%d\n",x+b[n-1]);
	}
}

