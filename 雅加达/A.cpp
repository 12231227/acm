#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;
int pos[maxn + 11];
int a[maxn + 11];

int main(){
	int n;
	scanf("%d",&n);
	int j = n;
	for (int i = 1; i <= n; i++,j--)
		pos[i] = j;
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	for (int i = 1; i <= n; i++) printf("%d%s",pos[a[i]] , i == n ? "\n" : " ");
}

