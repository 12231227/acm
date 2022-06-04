#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;

const int mol = 1e9 + 7;
vector <int> v;
int n,k,m;
int mod[211];

int qpow(int a,int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1ll * ans * a % mol;
		a = 1ll * a * a % mol;
		b >>= 1;
	}
	return ans;
}

int add(int a,int b) { a += b; if (a >= mol) a -= mol; return a; }

vector<int> solve(int n) {
	if (n == 1) return v;
	vector <int> p = solve(n / 2);
	vector <int> ans(m),res(m);
	for (int i = 0; i < m; i++){
		ans[i] = 0;
		for (int j = 0; j < m; j++)
			ans[i] = add(ans[i] , 1ll * p[j] * p[(i - j + m) % m] % mol);
	} 
	if (n % 2 == 0) return ans;
	for (int i = 0; i < m; i++) {
		res[i] = 0;
		for (int j = 0; j < m; j++)
			res[i] = add(res[i] , 1ll * ans[j] * v[(i - j + m) % m] % mol);
	}
	return res;
} 

int main(){ 
	scanf("%d %d %d",&n,&k,&m);
	int s = 0;
	for (int i = 1; i <= k; i++) { 
		if (i % m != 0) s++ , mod[i % m]++;
	} 
	int inv = qpow(s , mol - 2);
	v.pb(0);
	for (int i = 1; i < m; i++) mod[i] = 1ll * mod[i] * inv % mol , v.pb(mod[i]);
	printf("%d\n" , solve(n)[0]);
} 

