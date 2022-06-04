#include <bits/stdc++.h>
using namespace std;

int b[200011];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> b[i];
	int now = b[1];
	int mx = b[1];
	cout << mx << " ";
	for (int i = 2; i <= n; i++) {
		now = mx + b[i];
		mx = max(mx , now);
		cout << now << " ";
	}
}
