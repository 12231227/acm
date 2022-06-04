#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ull unsigned long long
using namespace std;

vector <int> v;
ull a[20][20];
ull h[20],d[20];

ull dfs10(int pos,int bit,int lim,int pre) {
	if (pos > v.size()) return 1;
	if (!lim && pre) return d[min((int)v.size() - pos + 1 , 10)];
	if (!lim) {
		int res = 10 - __builtin_popcount(bit);
		int resp = v.size() - pos + 1;
		if (resp > res) return 0;
		return a[res][resp];
	} 
	ull ans = 0;
	for (int i = 0; i <= v[pos - 1]; i++) { 
		if (bit & (1 << i)) continue;
		int add = (1 << i);
		if (i == 0 && pre) add = 0;
		ans += dfs10(pos + 1 , bit | add , lim & (i == v[pos - 1]) , pre & (i == 0));
	} 
	return ans;
} 

ull dfs16(int pos,int bit,int lim,int pre) { 
	if (pos > v.size()) return 1;
	if (!lim && pre) return h[min((int)v.size() - pos + 1 , 16)];
	if (!lim) { 
		int res = 16 - __builtin_popcount(bit);
		int resp = v.size() - pos + 1;
		if (resp > res) return 0;
		return a[res][resp];
	} 
	ull ans = 0;
	for (int i = 0; i <= v[pos - 1]; i++) { 
		if (bit & (1 << i)) continue;
		int add = (1 << i);
		if (i == 0 && pre) add = 0;
		ans += dfs16(pos + 1 , bit | add , lim & (i == v[pos - 1]) , pre & (i == 0));
	} 
	return ans;
} 

int get(char c) { 
	if (c >= '0' && c <= '9') return c - '0';
	return c - 'a' + 10;
} 

void print(ull x) {
	if (x == 0) {
		cout << x << endl;
		return;
	}
	v.clear();
	while (x) { v.pb(x % 16); x /= 16; }
	reverse(all(v));
	for (auto u : v) {
		if (u >= 10) { char c = 'a' + u - 10; cout << c; } else cout << u;
	}
	cout << endl;
}

void init() {
	a[0][0] = 1;
	for (int i = 1; i <= 16; i++) {
		a[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			a[i][j] = 1;
			for (int k = i; k >= i - j + 1; k--) a[i][j] *= k;
		}
	}
	d[1] = 10;
	for (int i = 2; i <= 10; i++) d[i] = a[9][i - 1] * 9;
	for (int i = 2; i <= 10; i++) d[i] += d[i - 1];
	h[1] = 16;
	for (int i = 2; i <= 16; i++) h[i] = a[15][i - 1] * 15;
	for (int i = 2; i <= 16; i++) h[i] += h[i - 1];
} 

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	int n; cin >> n;
	for (int cc = 1; cc <= n; cc++) {
		char c; int op;
		cin >> c >> op;
		if (op == 0) {
			if (c == 'd') {
				ull a,b; cin >> a >> b;
				ull ansl = 0 , ansr = 0;
				v.clear();
				while (b) { v.pb(b % 10); b /= 10; }
				reverse(all(v));
				ansr = dfs10(1 , 0 , 1 , 1);
				if (a) {
					a--;
					v.clear();
					while (a) { v.pb(a % 10); a /= 10; }
					reverse(all(v));
					ansl = dfs10(1 , 0 , 1 , 1);
				}
				cout << ansr - ansl << endl;
			}
			else {
				char a[100],b[100];
				cin >> a >> b;
				ull ansl = 0 , ansr = 0;
				v.clear();
				int l = strlen(b);
				for (int i = 0; i < l; i++) v.pb(get(b[i]));
				ansr = dfs16(1 , 0 , 1 , 1);
				l = strlen(a);
				if (l == 1 && a[0] == '0') {}
				else {
					ull p = 1; ull A = 0;
					for (int i = l - 1; i >= 0; i-- , p *= 16) A += get(a[i]) * p;
					A--;
					v.clear();
					while (A) { v.pb(A % 16); A /= 16; }
					reverse(all(v));
					ansl = dfs16(1 , 0 , 1 , 1);
				}
				ansr -= ansl;
				print(ansr);
			}
		}
		else {
			if (c == 'd') {
				ull rk; cin >> rk;
				if (d[10] < rk) { cout << "-" << endl;  continue; }
				if (rk <= 10) { cout << rk - 1 << endl; continue; }
				int len = 1;
				while (rk > d[len]) len++;
				ull cur = d[len - 1];
				int bit = 0;
				for (int i = 1; i <= len; i++) {
					for (int j = i == 1 ? 1 : 0; j <= 9; j++) {
						if (bit & (1 << j)) continue;
						int res = 9 - __builtin_popcount(bit);
						if (cur + a[res][len - i] >= rk) {
							bit ^= (1 << j); cout << j;
							break;
						}
						else cur += a[res][len - i];
					}
				}
				cout << endl;
			} 
			else {
				char ch[100]; cin >> ch;
				int l = strlen(ch);
				ull p = 1 , rk = 0;
				for (int i = l - 1; i >= 0; i-- , p *= 16) rk += p * get(ch[i]);
				if (h[16] < rk) { cout << "-" << endl;  continue; }
				if (rk <= 16) { rk--; print(rk); continue; }
				int len = 1;
				while (rk > h[len]) len++;
				ull cur = h[len - 1];
				int bit = 0;
				for (int i = 1; i <= len; i++) {
					for (int j = i == 1 ? 1 : 0; j <= 15; j++) {
						if (bit & (1 << j)) continue;
						int res = 15 - __builtin_popcount(bit);
						if (cur + a[res][len - i] >= rk) {
							bit ^= (1 << j);
							if (j < 10) cout << j;
							else {
								char c = 'a' + j - 10;
								cout << c;
							}
							break;
						}
						else cur += a[res][len - i];
					}
				}
				cout << endl;
			}
		} 
	} 
} 

