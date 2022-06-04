#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
 
ll f[2][101][5000];
ll a[111],b[111],c[111];
 
int main(){
	int t;
	scanf("%d",&t);
	while (t--) { 
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		} 
		memset(f,0,sizeof(f));
		f[0][1][n] = a[n];
		for (int i = n - 1; i >= 1; i--) {
		 for (int j = 1; j <= n - i + 1; j++) 
		  for (int k = (2 * i + j - 1) * j / 2; k <= (2 * n - j + 1) * j / 2; k++){ 
		    f[1][j][k] = 0;
		    if () f[1][j][k] = max(f[0][j][k] + b[i] * (k - i * j) , f[0][j][k] + c[i] * j);
		  	f[1][j][k] = max(f[1][j][k] , f[0][j - 1][k - i] + a[i]);
		  } 
		 for (int j = 1; j <= n - i + 1; j++) 
		  for (int k = (2 * i + j - 1) * j / 2; k <= (2 * n - j + 1) * j / 2; k++)
		   f[0][j][k] = f[1][j][k];
		}
		ll ans = 0;
		for (int j = 1; j <= n; j++) 
		 for (int k = (j + 1) * j / 2; k <= (2 * n - j + 1) * j / 2; k++)
		  ans = max(ans , f[1][j][k]);
		cout << ans << endl;
	} 
} 

