#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 2e5;
vector <int> pos[30];
char s[maxn + 11];

int main(){ 
	scanf("%s" , s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++) pos[s[i] - 'a'].pb(i);
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s" , s + 1);
		int len = strlen(s + 1);
		int p = 0;
		for (int i = 1; i <= len; i++) { 
			int ind = upper_bound(all(pos[s[i] - 'a']) , p) - pos[s[i] - 'a'].begin();
			if (ind == pos[s[i] - 'a'].size()) break;
			p = pos[s[i] - 'a'][ind];
			printf("%c" , s[i]);
		} 
		if (!p) printf("IMPOSSIBLE");
		printf("\n");
	} 
} 
