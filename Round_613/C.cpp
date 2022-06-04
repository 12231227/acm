#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b) { return b == 0 ? a : gcd(b , a % b); }
vector <ll> v;

int main(){
	ll x;
	cin >> x;
	for (ll i = 2;i <= sqrt(x); i++) {
		if (x % i == 0) { 
			v.push_back(i);
			if (i * i != x) v.push_back(x / i);
		}
	} 
	sort(v.begin() , v.end());
	ll a = 1; ll b = x;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= a && v[i] >= b) break;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] >= a && v[j] >= b) break;
			if (v[i] * v[j] / gcd(v[i] , v[j]) == x) 
				if (max(v[i] , v[j]) < max(a , b)) { a = v[i]; b = v[j]; }

		}
	}
	cout << a << " " << b << endl;
} 

