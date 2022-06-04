#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5;

char ch[maxn + 11];

struct node{
	int l,r,col;
	int len() { return r - l + 1; }
}seg[maxn + 11];

int main(){
	scanf("%s" , ch + 1);
	int n = strlen(ch + 1);
	int cnt = 0;
	char now = ch[1];
	int l = 1;
	for (int i = 2; i <= n; i++) {
		if (ch[i] == now) continue;
		seg[++cnt] = node{l , i - 1 , now - 'A'};
		l = i;
		now = ch[i];
	}
	seg[++cnt] = node{l , n , now - 'A'};
	if (cnt % 2 == 0) { printf("0\n"); return 0; }
	int pos = (cnt + 1) / 2;
	bool flag = true;
	if (seg[pos].len() >= 2) {
		int l = pos - 1 , r = pos + 1;
		while (l) {
			if (seg[l].col != seg[r].col || seg[l].len() + seg[r].len() == 2) { flag = false; break; }
			l--; r++;
		}
	}
	else flag = false;
	if (flag) printf("%d\n" , seg[pos].len() + 1); else printf("0\n");
}
