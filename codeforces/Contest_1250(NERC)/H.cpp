#include <bits/stdc++.h>
using namespace std;

int c[11];
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i <= 9; i++) cin >> c[i]; c[0]++;
		int mn = 1e6; int num;
		for (int i = 0; i <= 9; i++)
			if (c[i] < mn) {
				mn = c[i];
				num = i;
			}
		if (num == 0) {
			cout << 1;
			for (int i = 1; i <= mn; i++) cout << 0;
		}
		else for (int i = 1; i <= mn + 1; i++) cout << num;
		cout << endl;
	} 
} 

