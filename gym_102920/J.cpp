#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

bitset <500> bas;
int cnt[501],v[501];

struct BASE{
	bitset <500> d[500];
	int pos[500][501];
	void insert(bitset <500> x , int _pos) { 
		memset(v , 0 , sizeof(v));
		for (int i = 499; i >= 0; i--)
			if (x[i]) {
				if (d[i].count()) {
					x ^= d[i];
					for (int j = 1; j <= 500; j++) v[j] ^= pos[i][j];
				}
				else {
					d[i] = x;
					for (int j = 1; j <= 500; j++) pos[i][j] = v[j];
					pos[i][_pos] ^= 1;
					break;
				}
			}
	}
	bool check(bitset <500> x) {
		for (int i = 499; i >= 0; i--)
			if (x[i]) {
				if (d[i].count()) x ^= d[i]; else return false;
			}
		return x.count() == 0;
	}
	void query(bitset <500> x) {
		memset(cnt , 0 , sizeof(cnt));
		for (int i = 499; i >= 0; i--)
			if (x[i]) {
				for (int j = 1; j <= 500; j++)
					cnt[j] ^= pos[i][j];
				x ^= d[i];
			}
		for (int i = 1; i <= 500; i++)
			if (cnt[i]) cout << i << " ";
		cout << endl;
	}
} base;

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		bas.reset();
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			if (x) bas.set(j - 1);
		}
		base.insert(bas , i);
	} 
	for (int i = 0; i < n; i++) {
		bas.reset(); bas.set(i);
		if (!base.check(bas)) { cout << -1 << endl; return 0; }
	}
	for (int i = 0; i < n; i++) {
		bas.reset(); bas.set(i);
		base.query(bas);
	}
} 
