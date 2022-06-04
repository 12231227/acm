#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

int f[100];

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	ll x = n / 3;
	cout << x * (2 * x + 2 + n) - 5 * x * (x + 1) / 2 << endl;
} 
