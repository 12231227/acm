#include <cstdio>
#include <cstring>
using namespace std;

int ans[1000000];
bool vis[262144];

int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	int cnt = 0;
	memset(vis,false,sizeof(vis));
	vis[0] = vis[x] = true;
	for (int i = 1; i < (1 << n); i++)
	 if (i != x){
	 	if (vis[i] || vis[i ^ x]) continue;
	 	ans[++cnt] = i;
	 	vis[i] = true;
	 }
	printf("%d\n",cnt);
	for (int i = 1; i < cnt; i++) printf("%d ",ans[i] ^ ans[i - 1]);
	if (cnt >= 1)printf("%d\n",ans[cnt] ^ ans[cnt - 1]);
}

