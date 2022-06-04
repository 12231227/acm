#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;

int sl[maxn + 11][20],sr[maxn + 11][20];
int lg[maxn + 11];
int n;

int find(int x) {
	int i = 0;
	while ((1 << i) <= x) i++;
	return i - 1;
}

pair <int,int> query(int l,int r) {
	int j = lg[r - l + 1];
	return make_pair(max(sl[l][j] , sl[r - (1 << j) + 1][j]) , min(sr[l][j] , sr[r - (1 << j) + 1][j]));
}

bool check(int len) {
	for (int i = 1; i + len - 1 <= n; i++) {
		pair <int,int> pi = query(i , i + len - 1);
		if (pi.second - pi.first + 1 >= len) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l,r;
		lg[i] = find(i);
		cin >> l >> r;
		sl[i][0] = l;
		sr[i][0] = r;
	}
	for (int j = 1; j <= lg[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			sl[i][j] = max(sl[i][j - 1] , sl[i + (1 << (j - 1))][j - 1]);
			sr[i][j] = min(sr[i][j - 1] , sr[i + (1 << (j - 1))][j - 1]);
		}
	int L = 1; int R = n;
	int ans = 0;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (check(mid)) { ans = mid; L = mid + 1; } else R = mid - 1;
	}
	cout << ans << endl;
} 

