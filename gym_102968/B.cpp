/*  @author: AiharaShiro
	@createdate: 2021-03-31 13:45:12
	@Email：1150811645@qq.com  */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

char BUF[1 << 22], *ST, *EN;
#define gc (ST == EN && (ST = BUF, EN = BUF + fread(BUF, 1, 1 << 21, stdin), ST == EN) ? EOF : *ST++)
 
template<class T> void read(T &x){
	int f=0; x=0; char ch=gc;
	for(;!isdigit(ch);ch=gc) f|=(ch=='-');
	for(;isdigit(ch);ch=gc) x=x*10+ch-'0';
	if(f) x=-x;
}


int N;
const int maxn = 500005;
long long cost[maxn];
int input[maxn];
int K;
int D;
long long sumcost[105];
long long modcost[105][505];
long long dppre[105][505];
long long dpsuf[105][505];
long long ans[105][505];
const long long inf = 1e18;

int main() {
	read(N); read(K); read(D);
	for (int i = 0; i < N; i++) read(input[i]);
	for (int i = 0; i < N; i++) {
		read(cost[i]);
		sumcost[(i % K) + 1] += cost[i];
		modcost[(i % K) + 1][input[i] % D] += cost[i];
	}

	for (int j = 0; j <= K + 1; j++) {
		for (int k = 0; k < D; k++) {
			dppre[j][k] = inf;
			dpsuf[j][k] = inf;
		}
	}
	dppre[0][0] = 0;
	dpsuf[K + 1][0] = 0;

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < D; j++) {//上一个的和
			for (int k = 0; k < D; k++) {//本组改变为k
				dppre[i][(j + k) % D] = min(dppre[i - 1][j] + sumcost[i] - modcost[i][k], dppre[i][(j + k) % D]);
			}
		}
	}

	for (int i = K; i >= 1; i--) {
		for (int j = 0; j < D; j++) {
			for (int k = 0; k < D; k++) {
				dpsuf[i][(j + k) % D] = min(dpsuf[i + 1][j] + sumcost[i] - modcost[i][k], dpsuf[i][(j + k) % D]);
			}
		}
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < D; j++) {
			ans[i][j] = inf;
		}
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < D; j++) {//本组锁定为j
			for (int k = 0; k < D; k++) {//pre锁定为k
				int nowq = (D - ((j + k) % D)) % D;
				ans[i][j] = min(ans[i][j], sumcost[i] - modcost[i][j] + dppre[i - 1][k] + dpsuf[i + 1][nowq]);
			}
		}
	}

	int q;
	read(q);
	while (q--) {
		int pos;
		read(pos);
		pos--;
		printf("%lld\n" , ans[(pos % K) + 1][input[pos] % D]);
	}
	return 0;
}