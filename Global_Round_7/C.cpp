#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 998244353;
vector <int> v;
int pos[200011];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		pos[x] = i;
	}
	ll ans = 0;
	for (int i = n; i >= n - k + 1; i--) {
		ans += i;
		v.push_back(pos[i]);
	}
	cout << ans << " ";
	sort(v.begin() , v.end());
	ans = 1;
	for (int i = 1; i < v.size(); i++)
		ans = ans * (v[i] - v[i - 1]) % mol;
	cout << ans << endl;
} 

