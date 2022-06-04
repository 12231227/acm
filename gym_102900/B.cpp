#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

char s[1010][1010],ch[1010][1010];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s[i] + 1;
	for (int i = 1; i <= n; i++) cin >> ch[i] + 1;
	int cnt1 = 0 , cnt2 = 0;
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= m; j++)
			if (ch[i][j] != s[i][j]) cnt1++; else cnt2++;
	} 
	if (cnt1 <= cnt2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) cout << s[i][j];
			cout << endl;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i][j] == '.') cout << 'X'; else cout << '.';
			}
			cout << endl;
		}
	}
} 
