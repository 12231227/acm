#include <cstdio>
#include <algorithm>
using namespace std;
int a[100011];

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	int ans = 0;
	int last = a[1];
	int lastnum = 0;
	int num = 1;
	for (int i = 2; i <= n; i++)
	 if (a[i] == last) num++;
	 else{
	 	if (min(lastnum,num)*2 > ans) ans = min(lastnum,num)*2;
	 	lastnum = num;
	 	num = 1;
	 	last = a[i];
	 }
	if (min(lastnum,num)*2 > ans) ans = min(lastnum,num)*2;
	printf("%d\n",ans);
}

