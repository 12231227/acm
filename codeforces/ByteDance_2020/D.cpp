#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define int long long
using namespace std;

const int maxn = 1000;
int p[maxn + 11][5];
pll shot[maxn + 11];

signed main(){ 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,t; cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> p[i][3] >> p[i][2] >> p[i][1];
    for (int i = 1; i <= t; i++) {
        int x,y; cin >> x >> y;
        shot[i] = make_pair(p[x][y] * y , p[x][1] * y);
    }
    sort(shot + 1 , shot + 1 + t , [&](pll x,pll y) { return x.first - x.second > y.first - y.second; });
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i <= t; i++) {
        if (shot[i].second < shot[i].first && cnt < 6) {
            ans += shot[i].second;
            cnt++;
        } 
        else ans += shot[i].first;
    }
    printf("%lld.%lld\n" , ans / 100 , ans % 100);
} 
