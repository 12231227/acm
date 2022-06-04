#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn=150005;

struct point{
	int num; int u;
}l[maxn],r[maxn];

bool cmp(point a,point b)
{
	return a.num>b.num;
}

int main()
{
	int i,j,p,n;
	char ch;
	bool visl[maxn],visr[maxn];
	int ans[maxn][2];
	scanf("%d",&n);
	getchar();
	for (i=1;i<=n;i++)
	{
		ch=getchar();
		l[i].num=ch;
		l[i].u=i;
		visl[i]=false;
	}
	l[n+1].num=0;
	sort(l+1,l+1+n,cmp);
	getchar();
	for (i=1;i<=n;i++)
	{
		ch=getchar();
		r[i].num=ch;
		r[i].u=i;
		visr[i]=false;
	}
	r[n+1].num=0;
	sort(r+1,r+1+n,cmp);
	i=1; j=1;
	int tot=0;
	while (i<=n && j<=n)
	{
		if (l[i].num==63 || r[j].num==63) break;
		if (l[i].num==r[j].num)
		{
			tot++;
			ans[tot][0]=l[i].u;
			ans[tot][1]=r[j].u;
			visl[i]=true;
			visr[j]=true;
			i++;
			j++;
		}
		else if (l[i].num>r[j].num) i++;
		else j++;
	}
	while (l[i].num>63 && i<=n) i++;
	while (r[j].num>63 && j<=n) j++;
	p=j;
	if (l[i].num==63)
	 for (j=1;j<=n && i<=n;j++)
	 	if (!visr[j]) { tot++; 
	 		ans[tot][0]=l[i].u;
			ans[tot][1]=r[j].u;
			visr[j]=true;
		  i++; }
	if (r[p].num==63)
	{
		while (visr[p] && p<=n) p++;
	for (j=1;j<=n && p<=n;j++)
	 	if (!visl[j]) { tot++; 
	 		ans[tot][0]=l[j].u;
			ans[tot][1]=r[p].u;
		p++; }
	}
	printf("%d\n",tot);
	for (i=1;i<=tot;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
}

