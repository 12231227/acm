#include <bits/stdc++.h>
using namespace std;

int posl[222],posr[222],big[222];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(big , 0 , sizeof(big));
		int n;
		cin >> n;
		int l = (n + 1) / 2; int r = n + 1 - l;
		for (int i = 1; i <= l; i++) {
			for (int j = i + 1; j <= l; j++) {
				cout << "? " << i << " " << j << endl;
				char c; cin >> c;
				if (c == '>') big[j]++; else big[i]++;
			}
		}
		for (int i = 1; i <= l; i++) posl[big[i] + 1] = i;
		for (int i = l + 1; i <= n + 1; i++)
			for (int j = i + 1; j <= n + 1; j++) {
				cout << "? " << i << " " << j << endl;
				char c; cin >> c;
				if (c == '>') big[j]++; else big[i]++;
			}
		for (int i = l + 1; i <= n + 1; i++) posr[big[i] + 1] = i;
		cout << "? " << posl[l] << " " << posr[r] << endl;
		char c; cin >> c;
		if (c == '>') r--; else l--;
		for (int now = n + 2; now <= n * 2; now++) {
			if (r < 2) {
				cout << "? " << now << " " << posr[1] << endl;
				char c; cin >> c;
				if (c == '>') posr[2] = posr[1] , posr[1] = now; else posr[2] = now;
				r++;
			}
			else {
				for (int i = 1; i <= l; i++) {
					cout << "? " << now << " " << posl[i] << endl;
					char c; cin >> c;
					if (c == '<') big[now]++;
				}
				for (int i = l; i >= big[now] + 1; i--) posl[i + 1] = posl[i];
				l++; posl[big[now] + 1] = now;
			}
			cout << "? " << posl[l] << " " << posr[r] << endl;
			char c; cin >> c;
			if (c == '>') r--; else l--;
		}
		cout << "!" << endl;
	}
}