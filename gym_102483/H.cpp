#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int main(){ 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,c,b; cin >> n >> c >> b;
	for (int i = 1; i <= n; i++) bit[i] = 1;
	for (int i = 1; i <= b; i++) { int x; cin >> x; bit[x] = 0; }
	
} 