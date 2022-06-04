#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e7;
const ll mol = 1e9 + 7;

ll f[maxn + 11];

int main(){
	int n;
	f[1] = 1;
	f[2] = 5;
	f[3] = 15;
	for (int i = 4; i <= 100; i++) f[i] = ((f[i - 1] * 3 % mol - f[i - 2] * 3 % mol + mol) % mol + f[i - 3] + i) % mol;
	for (int i = 1; i <= 10; i++) cout << f[i] << endl;
} 

