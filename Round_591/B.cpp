#include <bits/stdc++.h> 
using namespace std;

int has[100];

int main(){
	int q;
	cin >> q;
	while (q--) {
		char s[111],t[111];
		scanf("%s %s",s + 1, t + 1);
		int n = strlen(s + 1);
		memset(has,0,sizeof(has));
		for (int i = 1; i <= n; i++) has[s[i] - 'a']++;
		bool can = false;
		for (int i = 1; i <= n; i++) if (has[t[i] - 'a']) { can = true; break; }
		if (can) printf("YES\n"); else printf("NO\n");
	}
}

