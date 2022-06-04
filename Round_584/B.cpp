#include <cstdio>
#include <cstring>
using namespace std;

int a[1111],b[1111];
int times[500001];
int pos[1111];
int main(){
	int n;
	scanf("%d",&n);
	char ch[1011];
	scanf("%s",ch);
	for (int i = 0; i < n; i++)
		pos[i + 1] = (ch[i] == '1');
	for (int i = 1; i <= n; i++) {
		scanf("%d %d",&a[i],&b[i]);
		if (pos[i]) {
			for (int j = 0; j < b[i]; j++) times[j]++;
			for (int j = b[i] + a[i]; j <= 50000; j += 2 * a[i])
			 for (int k = j; k <= j + a[i] - 1; k++) times[k]++;
		}
		else {
			for (int j = b[i]; j <= 50000; j += 2 * a[i])
			 for (int k = j; k <= j + a[i] - 1; k++) times[k]++;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 50000; i++) if (times[i] > ans) ans = times[i];
	printf("%d\n",ans);
} 

