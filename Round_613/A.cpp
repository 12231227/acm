#include <bits/stdc++.h>
using namespace std;
char ch[1000000];
int main(){
	int n; cin >> n;
	scanf("%s" , ch + 1);
	int l,r;
	l = r = 0;
	for (int i = 1; i <= n; i++)
		if (ch[i] == 'L') l++; else r++;
	printf("%d\n" , r + l + 1);
}
