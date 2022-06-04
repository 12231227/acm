#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
char ch[maxn + 11];

int main(){
	int n;
	cin >> n;
	scanf("%s",ch + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (ch[i] == '(') cnt++;
	if (cnt * 2 != n) { cout << 0 << endl << 1 << " " << 1 << endl; return 0; }
	int ans = 0;
	int l = 1; int r = 1;
	for (int i = 1; i <= n; i++) 
		for (int j = i + 1; j <= n; j++){ 
				swap(ch[i] , ch[j]);
				int now = 0;
				int minn = 0;
				for (int k = 1;k <= n; k++) {
					if (ch[k] == '(') now++; else now--;
					minn = min(now , minn);
				}
				int res = 0;
				for (int k = 1; k <= n; k++) {
					if (minn == 0) res++;
					if (ch[k] == '(') minn--; else minn++;
				}
				if (res > ans) {
					ans = res;
					l = i; r = j;
				}
				swap(ch[i] , ch[j]);
			}
	cout << ans << endl;
	cout << l << " " << r << endl;
}
