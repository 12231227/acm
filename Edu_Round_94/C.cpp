#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e5;
char s[maxn + 11];
int w[maxn + 11];

int main(){ 
	int t; scanf("%d",&t);
	while (t--) {
		scanf("%s" , s + 1);
		int x; scanf("%d",&x);
		int n = strlen(s + 1);
		for (int i = 1; i <= n; i++) w[i] = 1;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') continue;
			if (i - x > 0) w[i - x] = 0;
			if (i + x <= n) w[i + x] = 0;
		}
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0') continue;
			int l = i - x > 0 ? w[i - x] : 0;
			int r = i + x <= n ? w[i + x] : 0;
			if (!l && !r) { flag = false ; break; }
		}
		if (!flag) printf("-1\n");
		else{
		for (int i = 1; i <= n; i++) printf("%d" , w[i]);
		printf("\n");
	}
	} 
} 
