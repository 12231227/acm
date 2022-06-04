#pragma comment(linker, "/STACK:1024000000,1024000000")
/*
    Author: elfness@UESTC
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int oo = 1000000000;
const int P = 1000000007;
const int V = 2000100;

int pow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (LL) res * x % P;
        x = (LL) x * x % P; y /= 2;
    }
    return res;
}

int _, n, m, K, r, c, h;
int dp[V][2], cnt[V], mx[V], a[V];

int main() {
    scanf("%d", &_);
    for (int ca = 1; ca <= _; ++ca) {
        scanf("%d%d%d", &n, &m, &K);
        //for (int i = 1; i <= n + m; ++i) scanf("%d", &a[i]);
        for (int i = 1; i < n + m; ++i) mx[i] = 0;
        cnt[0] = 0;
        for (int i = 1; i < n + m; ++i) {
            if (i <= min(n, m)) cnt[i] = cnt[i - 1] + 1;
            else if (i <= max(n, m)) cnt[i] = cnt[i - 1];
            else cnt[i] = cnt[i - 1] - 1;
        }
        for (int i = 0; i < K; ++i) {
            scanf("%d%d%d", &r, &c, &h);
            int pos = r + c - 1;
            mx[pos] = max(mx[pos], h);
            --cnt[pos];
        }
        for (int i = 0; i <= n + m; ++i) dp[i][0] = dp[i][1] = 0;
        dp[0][0] = 1;
        for (int i = 1; i < n + m; ++i) {
            if (cnt[i] < 0) continue;
            if (mx[i] > a[i]) continue;
            if (mx[i] > a[i + 1]) continue;
            /*
            0->0 has a[i] && no a[i+1]
            0->1 has a[i] && has a[i+1]
            1->0 no a[i+1]
            1->1 has a[i+1]
            */
            if (a[i] < a[i + 1] && mx[i] < a[i + 1]) {
                if (mx[i] == a[i]) dp[i][0] += (LL) dp[i - 1][0] * pow(a[i], cnt[i]) % P;
                else dp[i][0] += (LL) dp[i - 1][0] * (pow(a[i], cnt[i]) - pow(a[i] - 1, cnt[i]) + P) % P;
            }
            if (a[i] == a[i + 1]) {
                if (mx[i] == a[i]) dp[i][1] += (LL) dp[i - 1][0] * pow(a[i], cnt[i]) % P;
                else dp[i][1] += (LL) dp[i - 1][0] * (pow(a[i], cnt[i]) - pow(a[i] - 1, cnt[i]) + P) % P;
            }
            if (mx[i] < a[i + 1]) {
                dp[i][0] += (LL) dp[i - 1][1] * pow(min(a[i], a[i + 1] - 1), cnt[i]) % P;
            }
            if(a[i + 1] <= a[i]) {
                if (mx[i] == a[i + 1]) dp[i][1] += (LL) dp[i - 1][1] * pow(a[i + 1], cnt[i]) % P;
                else dp[i][1] += (LL) dp[i - 1][1] * (pow(a[i + 1], cnt[i]) - pow(a[i + 1] - 1, cnt[i]) + P) % P;
            }
            dp[i][0] %= P;
            dp[i][1] %= P;
            //printf("Dp %d %d %d %d %d\n", i, cnt[i], mx[i], dp[i][0], dp[i][1]);
        }
        printf("Case #%d: %d\n", ca, dp[n + m - 1][1]);
    }
    return 0;
}

/*
1
2 2 1
2 2 2 2
2 2 2
*/

