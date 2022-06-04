#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

const int maxn = 2e3;

int l[maxn + 11],r[maxn + 11];
vector <int> v,ans;
vector <int> has[maxn + 11];

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d %d",&l[i],&r[i]);
	int m;
	scanf("%d",&m);
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d",&x);
		v.push_back(x);
	} 
	v.push_back(2e9);
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		int L = lower_bound(all(v) , l[i]) - v.begin();
		int R = upper_bound(all(v) , r[i]) - v.begin();
		for (int j = L; j < R; j++) has[i].push_back(v[j]);
		if (has[i].size() > 2) {
			flag = false;
			break;
		}
	}
	if (!flag) {
		printf("impossible\n");
		return 0;
	}
	l[n + 1] = r[n + 1] = -1;
	for (int i = 1; i <= n; i++) {
		if (has[i].size() == 2) continue;
		if (has[i].size() == 1) {
			if (has[i][0] == r[i]) ans.push_back(r[i] - 1);
			else {
				if (has[i + 1].size() == 2 && r[i] == l[i + 1]) {
					for (int j = r[i] - 1; ; j--)
						if (j != has[i][0]) { ans.push_back(j); break; }
				}
				else {
					ans.push_back(r[i]);
					if (r[i] == l[i + 1]) has[i + 1].push_back(r[i]);
				}
			}
		}
		else {
			if (has[i + 1].size() == 2 && r[i] == l[i + 1]) {
				ans.push_back(r[i] - 1);
				ans.push_back(r[i] - 2);
			}
			else {
				ans.push_back(r[i] - 1);
				ans.push_back(r[i]);
				if (l[i + 1] == r[i]) has[i + 1].push_back(r[i]);
			}
		} 
	} 
	printf("%d\n" , ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d%s" , ans[i] , i + 1 == ans.size() ? "\n" : " ");
} 

