#include <stdio.h>
#include <algorithm>
using namespace std;

struct p{
	int l,r;
}tmp[1501],ans[1501];
struct q{
	int num,l,r;
}f[2250010];
int a[1501];
int n,i,j,x,len,now,t,tot;

bool cmp(q a,q b)
{
	return ((a.num<b.num) || (a.num==b.num && a.r<b.r));
}

int main()
{
	scanf("%d",&n);
	a[0]=0;
	for (i=1;i<=n;i++)
	 {
	 	scanf("%d",&x);
	 	a[i]=a[i-1]+x;
	 }
	len=0;
	for (i=1;i<=n;i++)
	 for (j=i;j<=n;j++)
	 {
	 	len++;
	 	f[len].num=a[j]-a[i-1];
	 	f[len].l=i; f[len].r=j;
	 }
	sort(f+1,f+1+len,cmp);
	tot=0;
	i=j=1;
	now=f[1].num;
	while (i<=len)
	{
		now=f[i].num;
		while (f[i+1].num==now && i<len) i++;
		//j - i
		//e=f[j].r;
		t=1;  tmp[1].l=f[j].l; tmp[1].r=f[j].r;
		j++;
		while (j<=i)
		{
			if (f[j].l>tmp[t].r) { t++; tmp[t].l=f[j].l; tmp[t].r=f[j].r; }
			j++;
		}
		if (t>tot) {
			tot=t;
			for (int k=1;k<=t;k++) { ans[k].l=tmp[k].l; ans[k].r=tmp[k].r; }
 		}
		i++;
		j=i;
	}
	printf("%d\n",tot);
	for (i=1;i<=tot;i++) printf("%d %d\n",ans[i].l,ans[i].r);
}

