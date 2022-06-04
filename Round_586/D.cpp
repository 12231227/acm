#include <bits/stdc++.h> 
#define ll long long

using namespace std;

vector <ll> v[100];

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld",&x);
		ll tmp = x;
		int cnt = 0;
		while (x % 2 == 0) {
			cnt++;
			x /= 2;
		}
		v[cnt].push_back(tmp);
	} 
	int ans = 0;
	int ind;
	for (int i = 0; i <= 63; i++) {
		if (v[i].size() > ans) {
			ans = v[i].size();
			ind = i;
		}
	}
	printf("%d\n", n - ans);
	for (int i = 0; i <= 63; i++) {
		if (i == ind) continue;
		for (int j = 0; j < v[i].size(); j++) printf("%lld ",v[i][j]);
	}
} 

