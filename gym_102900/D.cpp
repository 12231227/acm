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
	int t; cin >> t;
	while (t--) {
		double n,p1,p2,v1,v2;
		cin >> n >> p1 >> v1 >> p2 >> v2;
		if (p1 > p2) { swap(p1 , p2); swap(v1 , v2); }
		double a = p1 , b = p2 - p1 , c = n - p2;
		double ans = min((n + min(a , n - a)) / v1 , (n + min(c , n - c)) / v2);
		ans = min(ans , max((a + b + min(a , b)) / v1 , c / v2));
		ans = min(ans , max(a / v1 , (b + c + min(b , c)) / v2));
		ans = min(max((a + b) / v2 , (b + c) / v1) , ans);
		
		double x = (2 * b * v2 + a * v2 - 2 * c * v1) / (v1 + 2 * v2);
		if (x >= 0 && x <= b) ans = min(ans , (2 * c + x) / v2);

		x = (2 * v1 * b + c * v1 - 2 * a * v2) / (v2 + 2 * v1);
		if (x >= 0 && x <= b) ans = min(ans , (2 * a + x) / v1);

		x = (2 * v1 * b + c * v1 - a * v2) / (2 * v1 + 2 * v2);
		if (x >= 0 && x <= b) ans = min(ans , (2 * x + a) / v1);

		x = (2 * c * v1 + b * v1 - 2 * a * v2) / (v1 + v2);
		if (x >= 0 && x <= b) ans = min(ans , (2 * a + x) / v1);

		printf("%.8lf\n" , ans);
	}
} 
