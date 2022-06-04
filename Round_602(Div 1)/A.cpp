#include <bits/stdc++.h>
using namespace std;

char ch[2111];
vector <pair<int,int> > ans;

int main(){
	int t;
	scanf("%d",&t);
	while (t--) {
		int n,k;
		scanf("%d %d",&n,&k);
		scanf("%s" , ch + 1);
		ans.clear();
		int s;
		if (ch[1] == '(') s = 1; else s = 0;
		for (int i = 2; i <= n; i++) {
			if (ch[i] == '(') {
				if (s + 1 == i) s++;
				else {
					ans.push_back(make_pair(s + 1 , i));
					reverse(ch + s + 1 , ch + i + 1);
					s++;
				}
			}
		}
		s = n / 2 + 1;
		k--;
		int i = 2;
		while (k) {
			reverse(ch + i , ch + s + 1);
			ans.push_back(make_pair(i , s));
			s++;
			i += 2;
			k--;
		}
		
		printf("%d\n" , ans.size());
		for (int i = 0; i < ans.size(); i++) printf("%d %d\n" , ans[i].first , ans[i].second);
	}
} 

