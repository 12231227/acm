#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	char ch[1111]; 
	while (t--) {
		int n;
		cin >> n;
		scanf("%s" , ch + 1);
		int ans = n;
		for (int i = 1; i <= n; i++) if (ch[i] == '1') ans++;
		for (int i = 1; i <= n; i++)
			if (ch[i] == '1') {
				int l = max(i , n - i + 1);
				ans = max(ans , 2 * l);
			}
		cout << ans << endl;
	}
}
