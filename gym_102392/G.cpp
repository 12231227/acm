#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

const int maxn = 1e6;

vector <int> x[111],y[111];
char ch[111];

int main(){
	int n,m,h;
	scanf("%d %d %d",&n,&m,&h);
	for (int i = n; i >= 1; i--) {
		scanf("%s" , ch + 1);
		for (int j = 1; j <= m; j++)
			if (ch[j] == '1') {
				x[i].pb(j);
			}
	}
	for (int i = n; i >= 1; i--) {
		scanf("%s" , ch + 1);
		for (int j = 1; j <= h; j++)
			if (ch[j] == '1') {
				y[i].pb(j);
			}
	}
	for (int i = 1; i <= n; i++) {
		if ((x[i].empty() && !y[i].empty()) || (!x[i].empty() && y[i].empty())) {
			printf("-1\n");
			return 0;
		}
	}

	int mx = 0; int mn = 0;
	for (int i = 1; i <= n; i++) {
		mx += (int)x[i].size() * (int)y[i].size();
		mn += max((int)x[i].size() , (int)y[i].size());
	}
	printf("%d\n" , mx);
	int tot = 0;
	int t = 0;
	for (int i = n; i >= 1; i--) {
		for (auto b : x[i])
			for (auto c : y[i]) {
				printf("%d %d %d\n" , t , b - 1, c - 1);
			}
		t++;
	}
	t = 0;
	printf("%d\n" , mn);
	for (int i = n; i >= 1; i--) {
		if (x[i].size() <= y[i].size()) {
			for (int j = 0; j < y[i].size() - x[i].size(); j++)
				printf("%d %d %d\n" , t , x[i][0] - 1 , y[i][j] - 1);
			for (int j = 0; j < x[i].size(); j++)
				printf("%d %d %d\n" , t , x[i][j] - 1 , y[i][j + y[i].size() - x[i].size()] - 1);
		}
		else {
			for (int j = 0; j < x[i].size() - y[i].size(); j++)
				printf("%d %d %d\n" , t , x[i][j] - 1 , y[i][0] - 1);
			for (int j = 0; j < y[i].size(); j++)
				printf("%d %d %d\n" , t , x[i][j + x[i].size() - y[i].size()] - 1 , y[i][j] - 1);
		}
		t++;
	}
} 

