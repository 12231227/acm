#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn =1e5 + 11;
int a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		if (a[i] == 0) cnt++;
	}
	if (cnt >= 2) printf("cslnb\n");
	else{
		sort(a + 1, a + 1 + n);
		bool flag = true;
		int same = 0;
		int samenum = 0;
		for (int i = 1; i < n; i++)
		 if (a[i] == a[i + 1]) { same++; samenum = a[i]; }
		if (same > 1) printf("cslnb\n");
		else{
			long long sum = 0;
			for (int i = 1; i <= n; i++) if (a[i] == samenum - 1) flag = false;
			for (int i = 1; i <= n; i++) {
				sum += (long long)(a[i] - (i - 1));
				if (a[i] < i - 1) { flag = false; break; }
			}
			if (!flag) printf("cslnb\n");
			else if (sum % 2 == 0) printf("cslnb\n");
			else printf("sjfnb\n");
		}
	}
}

