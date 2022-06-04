#include <stdio.h>
using namespace std;
int main()
{
	int n,i,ans,cnt;
	int a[400005];
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]),a[n+i]=a[i];
	ans=0; cnt=0;  
	for (i=1;i<=2*n;i++)
	 if (a[i]==0) {
	 	if (cnt>ans) ans=cnt;
	 	cnt=0;
	 }
	 else cnt++;
	 printf("%d\n",ans);
}

