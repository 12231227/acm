#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int maxn = 1e4;

int f[maxn + 11][maxn + 11];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n,k; cin >> n >> k;
		k--;
		f[0][0] = k;
		for (int i = 0; i < n - 1; i++)
			for (int j = i , k = i - j; j >= 0; j-- , k++){
				f[j + 1][k] += f[j][k] / 2;
				f[j][k + 1] += f[j][k] / 2;
				if (f[j][k] % 2 == 1) f[j + 1][k]++;
			}
		int x = 0 , y = 0;
		while (x + y < n - 1) { 
			if (f[x][y] & 1) y++; else x++;
		}
		printf("%d\n" , y);
		for (int i = 0; i < n - 1; i++)
			for (int j = i , k = i - j; j >= 0; j-- , k++) f[j + 1][k] = f[j][k + 1] = 0;
	} 
} 

