#include <bits/stdc++.h>
using namespace std;
int main(){ 
	int t;
	cin >> t; 
	while (t--) {
		int a,b,c;
		cin >> a >> b >> c;
		int ans = 0;
		for (int x = 0; x <= a; x++)
			for (int y = 0; y <= c / 2; y++){
				if (2 * x + y > b) continue;
				ans = max(ans , 3 * x + 3 * y);
			}
		cout << ans << endl;
	}
} 

