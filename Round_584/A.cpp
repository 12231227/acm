#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[111];
bool vis[111];
int main(){ 
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	memset(vis,false,sizeof(vis));
	sort(a + 1,a + 1 + n);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		cnt++;
		for (int j = i + 1; j <= n; j++) 
		 if (a[j] % a[i] == 0) vis[j] = true;
	}
	printf("%d\n",cnt);
} 

