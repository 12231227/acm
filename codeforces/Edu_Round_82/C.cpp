#include <bits/stdc++.h>
using namespace std;

char ch[211];
set <int> s[50];
vector <int> v;
bool vis[66];

int main(){
	int t;
	cin >> t;
	while (t--) {
		scanf("%s" , ch + 1);
		int n = strlen(ch + 1);
		if (n == 1) {
			printf("YES\n");
			for (int i = 1; i <= 26; i++) printf("%c" , i + 'a' - 1);
			printf("\n");
			continue;
		}
		for (int i = 1; i <= 26; i++) s[i].clear(),vis[i] = false;
		for (int i = 1; i < n; i++) {
			s[ch[i] - 'a' + 1].insert(ch[i + 1] - 'a' + 1);
			s[ch[i + 1] - 'a' + 1].insert(ch[i] - 'a' + 1);
		}
		v.clear();
		bool flag = true;
		for (int i = 1; i <= 26; i++){
			if (s[i].size() == 1) v.push_back(i);
			if (s[i].size() > 2) flag = false;
		}
		if (v.size() != 2 || !flag) { printf("NO\n"); continue; }
		printf("YES\n");
		int now = v[0];
		while (s[now].size()) {
			printf("%c" , now + 'a' - 1);
			vis[now] = true;
			int p = *s[now].begin();
			s[p].erase(now);
			now = p;
		} 
		printf("%c" , now + 'a' - 1);
		vis[now] = true;
		for (int i = 1; i <= 26; i++) if (!vis[i]) printf("%c" , i + 'a' - 1);
		printf("\n");
	} 
} 

