#include <bits/stdc++.h>
#define pb emplace_back
#define VI vector <int>
using namespace std;

VI row,cul;
vector<pair<VI , VI> > ans;

int check(int x,int i) { return (x & (1 << i)) > 0; }

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int l = 0;
	while ((1 << l) <= n) l++;
	for (int b = 0; b < 2;b++){
		for (int i = 0; i < l; i++){
			row.clear(); cul.clear();
			for (int j = 1; j <= n; j++) {
				if (check(j , i) == b) row.pb(j);
				else if (j == n) cul.pb(j);
				else if (check(j + 1 , i) != b) cul.pb(j);
			}
			if (row.empty() || cul.empty()) continue;
			ans.pb(make_pair(row , cul));
		}
	}
	for (int i = 0; i < l - 1; i++) {
		int suf = (1 << (i + 1)) - 1;
		cul.clear(); row.clear();
		for (int j = 1; j <= n; j++)
			if ((j & suf) == suf && (j & (1 << (i + 1))) == 0) cul.pb(j);
		for (int j = 1; j <= n; j++){
			bool flag = true;
			for (auto x : cul)
				if (x == j || x + 1 == j) { flag = false; break; }
			if (flag) row.pb(j);
		}
		if (row.empty() || cul.empty()) continue;
			ans.pb(make_pair(row , cul));
	} 
	cout << ans.size() << endl;
	for (auto pi : ans) {
		cout << pi.first.size();
		for (auto x : pi.first) cout << " " << x; cout << endl;
		cout << pi.second.size();
		for (auto x : pi.second) cout << " " << x; cout << endl;
	}
} 

