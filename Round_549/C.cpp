#include <cstdio>
using namespace std;

const int maxn=1e5+10;
int p[maxn],son[maxn],c[maxn],res[maxn],ans[maxn];

int main()
{
	int n,root;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d %d",&p[i],&c[i]);
	for (int i=1;i<=n;i++) if (i!=root){
		son[p[i]]++;
		res[p[i]]+=c[i];
	}
	int tot=0;
	for (int i=1;i<=n;i++)
	 if (son[i]==res[i] && c[i]==1) ans[++tot]=i;
	if (!tot) printf("-1\n");
	else{
		for (int i=1;i<tot;i++) printf("%d ",ans[i]);
		printf("%d\n",ans[tot]);
	}
}

