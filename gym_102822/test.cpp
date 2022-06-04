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
    int t; cin >> t;
    int c = 0;
    while (t--) {
        ++c;
        ll d01,d02,d12; cin >> d01 >> d02 >> d12;
        if (d01 > d02) swap(d01 , d02);
        ll s1 = 8 * d01 * d02;
        ll s2 = 8 * d01 * d02;
        ll p = 4 * (d01 + 1) * (d02 - d01) + 4 * d01;
        ll l = d02 - d01 , r = d01 + d02;
        printf("Case #%d: " , c);
        if (d12 < l || d12 > r) {
        	printf("0\n");
        	continue;
		}
		if (d02 == 0) {
			printf("%d\n" , d12 == 0 ? 1 : 0);
			continue;
		}
        if (d01 == 1) {
            if (d12 == l) printf("%lld\n" , p);
            else if (d12 == r) printf("%lld\n" , s1 - p + s2);
            else printf("0\n");
            continue;
        }
        if (d12 == l) printf("%lld\n" , p);
        else if ((d12 - l) % 2 == 1) printf("0\n");
        else {
            ll t = (d12 - l) / 2;
            ll fi = 24 + 8 * (d01 - 2) + (d02 - d01) * 8;
            if (d12 < r) {
                printf("%lld\n" , 8 * ((d12 - l) / 2 - 1) + fi);
            }
            else {
                ll o = (2 * fi + 4 * (r - l - 4)) / 4 * (r - l - 2);
                printf("%lld\n" , s1 - p - o + s2);
            }
        }
    }
} 

