#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int a[maxn + 11];
vector <int> pos[maxn + 11];
int n;

int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) pos[i].clear();
		bool can = false;
		for (int i = 1; i <= n; i++) {
			scanf("%d",&a[i]);
			pos[a[i]].push_back(i);
		}
		for (int i = 1; i <= n; i++) if (pos[i].size() >= 2) can = true;
		if (!can) { printf("-1\n"); continue; }
		int minn = n;
		for (int i = 1; i <= n; i++) {
			if (pos[i].size() <= 1) continue;
			for (int j = 1; j < pos[i].size(); j++) minn = min(minn , pos[i][j] - pos[i][j - 1] + 1);
		}
		printf("%d\n" , minn);
	}
}

