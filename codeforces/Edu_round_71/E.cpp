#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << "?";
    for (int i = 0; i < 100; i++)
    	cout << " " << (i << 7) + 127;
	cout << endl;
	int t;
	cin >> t;
	int two;
	int ans = 0;
	for (int i = 0; i < 7; i++){
		two = i == 0 ? 1 : two * 2;
		if( (t & (1 << i)) == 0) ans += two;
	}
	cout << "?";
	for (int i = 16256; i < 16356; i++){
		cout << " " << i;
	}
	cout << endl;
	cin >> t;
	for (int i = 7; i < 14; i++){
		two *= 2;
		if( (t & (1 << i)) == 0) ans += two;
	}
	cout << "! " << ans << endl;
} 

