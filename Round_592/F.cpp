#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const int maxn = 2e5;

char ch[maxn + 11];
int p[maxn + 11];
vector <int> v;

int main(){
	int n,k;
	cin >> n >> k;
	scanf("%s" , ch + 1);
	for (int i = 1; i < n; i++) if (ch[i] == ch[i + 1]) p[i] = p[i + 1] = 1;
	if (ch[1] == ch[n]) p[1] = p[n] = 1;
	v.pb(0);
	for (int i = 1; i <= n; i++)
		if (p[i] == 1) v.pb(i);
	if (v.size() == 1) {
		for (int i = 1; i <= n; i++){
			if (k & 1) printf("%c" , 'B' + 'W' - ch[i]);
			else printf("%c",ch[i]);
		}
		return 0;
	}
	v.pb(n + 1);
	for (int i = 1; i <= n; i++) {
		if (p[i] == 1) continue;
		int rig = lower_bound(all(v) , i) - v.begin();
		int lef = rig - 1;
		int disl,disr;
		if (v[rig] == n + 1) {
			rig = 1;
			disr = n - i + v[1];
		} else disr = v[rig] - i;
		if (v[lef] == 0) {
			lef = v.size() - 2;
			disl = n - v[lef] + i;
		} else disl = i - v[lef];
		lef = v[lef];
		rig = v[rig];
		if (disl < disr) {
			if (k >= disl) ch[i] = ch[lef]; else ch[i] = k % 2 == 0 ? ch[i] : 'B' + 'W' - ch[i];
		}
		else {
			if (k >= disr) ch[i] = ch[rig]; else ch[i] = k % 2 == 0 ? ch[i] : 'B' + 'W' - ch[i];
		}
	}
	for (int i = 1; i <= n; i++) printf("%c",ch[i]);
} 

