#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int p[10100];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	stack <int> s;
	for (int i = 1; i <= n; i++) s.push(i);
	int ans = 0;
	for (int i = 1; i <= n; i++) ans ^= i;
	while (s.size() > 1) {
		int x = s.top(); s.pop();
		int y = s.top(); s.pop();
		int a,b;
		cout << "? " << x << " " << y << endl; cin >> a;
		cout << "? " << y << " " << x << endl; cin >> b;
		if (a > b) { p[x] = a; s.push(y); ans ^= a; }
		else { p[y] = b; s.push(x); ans ^= b; }
	} 
	for (int i = 1; i <= n; i++) if (!p[i]) p[i] = ans;
	cout << "!";
	for (int i = 1; i <= n; i++) cout << " " << p[i];
	cout << endl;
} 
