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
char s[maxn + 11],t[maxn + 11];

int main(){ 
	scanf("%s" , s + 1);
	scanf("%s" , t + 1);
	int n = strlen(s + 1);
	int m = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') m = i; else break;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (s[i] == t[i]) continue;
		if (s[i] < t[i]) ans = -1; else ans = 1;
		break;
	}
	if (ans == 0) {
		int l1 = strlen(s + 1);
		int l2 = strlen(t + 1);
		if (l1 != l2) {
			if (l1 > l2) ans = 1; else ans = -1;
		}
		else {
			for (int i = m + 1; i <= l1; i++) {
				if (s[i] == t[i]) continue;
				if (s[i] < t[i]) ans = -1; else ans = 1;
				break;
			}
		}
	}
	if (ans == -1) printf("<\n"); else if (ans == 0) printf("=\n"); else printf(">\n");
} 
