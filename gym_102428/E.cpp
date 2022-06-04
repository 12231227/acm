#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5;
vector <int> pos;
char ch[maxn + 11];

int main(){
	scanf("%s" , ch + 1);
	int n = strlen(ch + 1);
	int s;
	scanf("%d",&s);
	int last = 0;
	for (int i = 1; i <= n; i++) 
		if (ch[i] == 'E') { pos.push_back(i); last = i; }
	if (last == 0) { printf("0\n"); return 0; }
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int p;
		if (i > last) p = pos[0];
		else p = pos[lower_bound(pos.begin() , pos.end() , i) - pos.begin()];
		int dis = p >= i ? p - i + 1 : n - i + 1 + p;
		if (dis > s) continue;
		ans += s - dis + 1;
	} 
	printf("%lld\n" , ans);
	return 0;
} 

