#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int a[maxn + 11];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int _;
	for (cin >> _;_;_--) {
		int n; cin >> n;
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] != a[1]) flag = false;
		}
		if (flag) {
			cout << 1 << endl;
			for (int i = 1; i <= n; i++) cout << 1 << " ";
			cout << endl;
			continue;
		}
		if (n % 2 == 0) {
			cout << 2 << endl;
			for (int i = 1; i <= n; i++) {
				int num = i % 2 == 1 ? 1 : 2;
				cout << num << " ";
			}
			cout << endl;
			continue; 
		}
		int u = 0;
		for (int i = 2; i <= n; i++) if (a[i] == a[i - 1]) u = i;
		if (!u) {
			if (a[1] == a[n]) {
				cout << 2 << endl << 2 << " ";
				int num = 0;
				for (int i = 2; i < n; i++) {
					num = num + 1; if (num == 3) num = 1;
					cout << num << " ";
				}
				cout << 2 << endl;
			}
			else {
				cout << 3 << endl << 3 << " ";
				for (int i = 2; i <= n; i++) {
					int num = i % 2 == 1 ? 1 : 2;
					cout << num << " ";
				}
				cout << endl;
			}
		}
		else {
			cout << 2 << endl;
			int num = 0;
			for (int i = 1; i < u; i++) {
				num = num + 1; if (num == 3) num = 1;
				cout << num << " ";
			}
			cout << num << " ";
			for (int i = u + 1; i <= n; i++){
				num = num + 1; if (num == 3) num = 1;
				cout << num << " ";
			}
			cout << endl;
		}
	}
}

