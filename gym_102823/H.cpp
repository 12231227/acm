#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e4;
char s1[maxn + 11],s2[maxn + 11],ans[maxn + 11];
int s[maxn + 11];

int main(){ 
	int t; scanf("%d" , &t);
	int cas = 0;
	while (t--) {
		cas++;
		scanf("%s" , s1 + 1); scanf("%s" , s2 + 1);
		int n = strlen(s1 + 1);
		for (int i = 1; i <= n; i++) {
			if (s1[i] == s2[i]) s[i] = 0; else s[i] = 1;
		} 
		s[n + 1] = 0;
		for (int i = n - 1; i >= 1; i--) s[i] += s[i + 1];
		int cur = 0;
		for (int i = 1; i <= n; i++) { 
			int tmp = cur;
			if (s1[i] != 'a') tmp++;
			if (s2[i] != 'a') tmp--;
			if (abs(tmp) <= s[i + 1]) {
				ans[i] = 'a';
				cur = tmp;
				continue;
			}

			char cu = s1[i]; tmp = cur;
			if (s2[i] != cu) tmp--;
			char fu = (abs(tmp) <= s[i + 1]);

			char cd = s2[i] ; tmp = cur;
			if (s1[i] != cd) tmp++;
			char fd = (abs(tmp) <= s[i + 1]);

			char ce; tmp = cur;
			for (ce = 'a' ; ce <= 'z'; ce++)
				if (ce != s1[i] && ce != s2[i]) break;
			char fe = (abs(tmp) <= s[i + 1]);

			char ret = 'z';
			if (fu && cu < ret) ret = cu;
			if (fd && cd < ret) ret = cd;
			if (fe && ce < ret) ret = ce;
			ans[i] = ret;
			if (ans[i] != s1[i]) cur++;
			if (ans[i] != s2[i]) cur--;
		} 
		printf("Case %d: " , cas);
		for (int i = 1; i <= n; i++) printf("%c" , ans[i]);
		printf("\n");
	} 
} 
