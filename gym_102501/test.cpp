#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int n = 350125310;
const ll m = 1099511627776;
const int xh = 182129209;

int main(){ 
	freopen("out.txt","w",stdout);
	ll s = 516914;
	ll cnt = 0;
	for (int i = 350125310; i < n + xh; i++) { 
		if (s % 2 == 0) cnt++;
//		if (i % 1000000 == 0) {
//			//cout << "a[" << i / 1000000 << "] = " << cnt << endl;
//			cout << cnt << ",";
//		}
		s = (s + (s >> 20) + 12345) % m;
	} 
	cout << cnt << endl; 
} 

