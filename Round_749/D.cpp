#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[111],bef[111],nxt[111];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) nxt[i] = -1 , bef[i] = -1;
	for (int i = 1; i <= n; i++) {
		cout << "?";
		for (int j = 1; j < i; j++) cout << " 1";
		cout << " 2";
		for (int j = i + 1; j <= n; j++) cout << " 1";
		cout << endl;
		int ind;
		cin >> ind;
		if (ind == i || ind == 0) continue;
		nxt[i] = ind;
		bef[ind] = i;
	}
	for (int i = 1; i <= n; i++) {
		cout << "?";
		for (int j = 1; j < i; j++) cout << " 2";
		cout << " 1";
		for (int j = i + 1; j <= n; j++) cout << " 2";
		cout << endl;
		int ind;
		cin >> ind;
		if (ind == i || ind == 0) continue;
		nxt[ind] = i;
		bef[i] = ind;
	} 
	int cur = -1;
	for (int i = 1; i <= n; i++)
		if (bef[i] == -1) cur = i , a[i] = 1;
	for (int i = 2; i <= n; i++) {
		cur = nxt[cur];
		a[cur] = i;
	}
	cout << "!";
	for (int i = 1; i <= n; i++) cout << " " << a[i];
	cout << endl;
} 
