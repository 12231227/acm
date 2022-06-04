#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

int pos[maxn + 11];
int a[maxn + 11];

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		pos[x] = i;
	}
	int m = n + 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	}
	for (int i = n; i >= 1; i--) {
		if (m < pos[a[i]]) cnt++;
		m = min(m , pos[a[i]]);
	}
	printf("%d\n" , cnt);
}

