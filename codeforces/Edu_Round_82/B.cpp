#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--) {
		int n,a,b;
		cin >> n >> a >> b;
		int N = n;
		n = (n + 1) / 2;
		long long day = 1ll * n / a * (a + b);
		if (n % a == 0) day -= b;
		else day += n - n / a * a;
		printf("%lld\n" , max(day , 1ll * N));
	}
} 

