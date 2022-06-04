#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

int a[maxn + 11];
vector <int> v[32];

int main() {
	int n;
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d" , &a[i]);
		for (int j = 0; j < 30; j++)
			if (a[i] & (1 << j)) v[j].emplace_back(a[i]);
	}
	int pos = -1;
	for (int i = 29; i >= 0; i--)
		if (v[i].size() == 1) { pos = i; break; }
	if (pos == -1) {
		for (int i = 1; i <= n; i++) printf("%d " , a[i]);
	}
	else {
		printf("%d " , v[pos][0]);
		for (int i = 1; i <= n; i++)
			if (a[i] != v[pos][0]) printf("%d " , a[i]);
	}
} 

