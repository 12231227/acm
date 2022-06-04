#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9;

int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("in.txt","w",stdout);
	int n = 50; cout << n << endl;
	for (int i = 1; i <= n; i++) cout << rng() % 100 << " ";
	cout << endl;
} 