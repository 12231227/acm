#include <cstdio>

using namespace std;
const int maxn = 2e5;
int fa[maxn + 11],cnt[maxn + 11];

int find(int x) { return fa[x] = (x == fa[x] ? x : find(fa[x])); } 

void merge(int x,int y){
	int fax = find(x);
	int fay = find(y);
	if (fax == fay) return;
	cnt[fax] += cnt[fay];
	fa[fay] = fax;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i = 1; i <= n; i++) fa[i] = i , cnt[i] = 1;
	for (int i = 1; i <= k; i++) { 
		int x,y;
		scanf("%d %d",&x,&y);
		merge(x , y);
	} 
	int happy = 0;
	for (int i = 1; i <= n; i++) 
	 if (find(i) == i) happy += cnt[i] - 1;
	printf("%d\n" , k - happy);
}

