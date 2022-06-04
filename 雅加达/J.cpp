#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, k, g1, g2, g3;
int dp[100005][55];
char inputs[100005];
const int inf = 1e9 + 77;

int main() {
	scanf("%d%d%d%d%d", &n, &k, &g1, &g2, &g3);
	scanf("%s", inputs + 1);
	int stones = 0;
	//int type3 = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 50; j++) {
			dp[i][j] = -inf;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 50; j++) {
			dp[i][j] = dp[i - 1][j];
		}
		if (inputs[i] == '#')
			stones++;
		if (i >= 2 && inputs[i] == '.' &&inputs[i - 1] == '.') {
			for (int j = 0; j <= 50; j++) {
				dp[i][j] = max(dp[i - 2][j] + g2, dp[i][j]);
			}
		}
		if (i >= 3 && inputs[i] == '.' && inputs[i - 1] == '#' && inputs[i - 2] == '.') {
			for (int j = 0; j <= 50; j++) {
				dp[i][j + 1] = max(dp[i][j + 1], dp[i - 3][j] + g3);
			}
		}
	}
	int ans = 0;
	for (int j = 0; j <= 50; j++) {
		if (dp[n][j] < 0)
			continue;
		int ty3 = j;
		int ty2 = (dp[n][j] - (g3 * j)) / g2;
		int remainspace = n - ty2 * 2 - ty3 * 3 - (stones - ty3);
		int ty1 = k;
		if (remainspace >= ty1)
			ans = max(ans, dp[n][j] + ty1 * g1);
		else
		{
			int tmp = dp[n][j];
			tmp = tmp + remainspace * g1;
			ty1 -= remainspace;
			int flag = 0;
			if (g2 > g3) {
				flag = 1;
				swap(g2, g3);
				swap(ty2, ty3);
			}
			if (g1 * 2 > g2) {
				if (ty2 * 2 <= ty1) {//ty2可被换完
					tmp = tmp + ty2 * 2 * g1 - ty2 * g2;
					ty1 -= ty2 * 2;
					if (g1 * 2 > g3) {
						if (ty3 * 2 <= ty1) {//ty3可被换完
							tmp = tmp + ty3 * 2 * g1 - ty3 * g3;
						}
						else//ty3不可被换完
						{
							tmp = tmp + (ty1 / 2) * 2 * g1 - (ty1 / 2) * g3;
							ty1 -= (ty1 / 2) * 2;
							ty3 -= (ty1 / 2);
							if (ty3 > 0 && ty1 == 1 && g1 > g3)
								tmp = tmp + g1 - g3;
						}
					}
				}
				else//ty2不可被换完
				{
					tmp = tmp + (ty1 / 2) * 2 * g1 - (ty1 / 2) * g2;
					ty1 -= (ty1 / 2) * 2;
					ty2 -= (ty1 / 2);
					if (ty2 > 0 && ty1 == 1 && g1 > g2)
						tmp = tmp + g1 - g2;
				}
			}
			if (flag) {
				swap(g2, g3);
				swap(ty2, ty3);
			}
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}
