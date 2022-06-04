/*  @author: AiharaShiro
    @createdate: 2020-12-18 13:13:09
    @Email£º1150811645@qq.com  */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int n, m;
const double pi = acos(-1.0);
double dp[505][505];

void init(){
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= m;j++){
            dp[i][j] = min(pi * ((double)j / (double)m) * i, 2.0 + dp[i - 1][j]);
        }
    }
    return;
}

double sum[505];
void getsum(){
    for (int len = 0; len <= m;len++){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                sum[len] += dp[min(i, j)][len] + abs(i - j);
            }
        }
    }
    sum[0] /= 2;
    return;
}

double getans(){
    double ans = 0;
    for (int i = 0; i < m;i++){
        ans += sum[i];
    }
    ans *= 2 * m;
    ans += m * sum[m];
    ans += m * n * (n + 1);
    return ans;
}
int main(){
    //std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    init();
    getsum();
    printf("%.8lf\n", getans());
    return 0;
} 

