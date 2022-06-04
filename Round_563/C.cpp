#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 11;
int ans[maxn];
int prime[maxn];
bool vis[maxn];

int main(){
	int n;
	scanf("%d",&n);
	memset(vis,false,sizeof(vis));
	int cnt = 0;
	for (int i = 2; i <= n; i++){
		if (!vis[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && prime[j] * i <= n; j++){
			vis[prime[j] * i] = true;
			if (i % prime[j] == 0) break;
		}
	}
	memset(ans,0,sizeof(ans));
	int now = 1;
	for (int i = 1; i <= cnt; i++){
	 for (int j = 1; prime[i] * j <= n; j++)
	  if (ans[prime[i] * j] == 0) ans[prime[i] * j] = now;
	 now++;
	}
	for (int i = 2; i < n; i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
}

