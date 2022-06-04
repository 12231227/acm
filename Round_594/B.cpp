#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 100000;

ll a[maxn + 11];

int main(){
	int n;
	cin >> n;
	ll l = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l += a[i];
	}
	sort(a + 1 , a + 1 + n);
	ll p = 0;
	for (int i = 1; i <= n / 2; i++) p += a[i];
	l -= p;
	cout << l * l + p * p << endl;
} 

