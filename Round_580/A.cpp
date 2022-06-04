#include <cstdio>
using namespace std;

const int maxn = 1000;

bool vis[maxn + 11] = {false};
int a[maxn + 11];
int b[maxn + 11];

int main(){
	int n,m;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) { scanf("%d",&a[i]); vis[a[i]] = true; }
	scanf("%d",&m);
	for (int i = 1; i <= m; i++) { scanf("%d",&b[i]); vis[b[i]] = true; }
	bool find = false;
	for (int i = 1; i <= n; i++){
	 if (find) break;
	 for (int j = 1; j <= m; j++)
	  if (vis[a[i] + b[j]] == false){
	  	find = true;
	  	printf("%d %d\n",a[i],b[j]);
	  	break;
	  }
	}
}

