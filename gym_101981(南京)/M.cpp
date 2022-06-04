#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
 
char inputs[1000005];//处理前字符串
char S[2000005];//处理后字符串
int radiusS[2000005];//回文半径
int radiusT[2000005];
 
long long cntnum[1000005];
 
int makestr(int len) {//字符串处理
	//int len = strlen(inputs);
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		S[cnt++] = '#';
		S[cnt++] = inputs[i];
	}
	S[cnt++] = '#';
	return cnt;
}
 
int manacher(int radius[],int lent) {
	memset(radius, 0, sizeof(radius));
	int len = makestr(lent);
	int R = -1;//最右回文右边界
	int C = -1;//最右回文右边界的对称中心
	int maxone = -1;
	for (int i = 0; i < len; i++) {
		if (i <= R) {//下一个移动位置在R内
			radius[i] = min(radius[2 * C - i], R - i + 1);//满足既在R内又在回文串的回文串内的元素必定回文
		}
		else
		{
			radius[i] = 1;
		}
		while (i + radius[i] < len && i - radius[i] > -1) {//限制边界
			if (S[i - radius[i]] == S[i + radius[i]]) {//向两边扩展
				radius[i]++;
			}
			else
			{
				break;
			}
		}
		if (i + radius[i] > R) {//更新R,C
			R = i + radius[i] - 1;
			C = i;
		}
		//maxone = max(maxone, radius[i]);
	}
	//return maxone - 1;
	return len;
}
 
/*bool query(int l, int r) {
	return radius[l + r + 1] >= r - l + 1;
}*/
 
signed main() {
	scanf("%s", &inputs);
	int rallenS = strlen(inputs);
	int lenS = manacher(radiusS,rallenS);
	scanf("%s", &inputs);
	int rallenT = strlen(inputs);
	int lenT = manacher(radiusT,rallenT);
	for (int i = 0; i < lenS; i++) {
		cntnum[radiusS[i] - 1]++;
	}
	for (int i = rallenS - 2; i >= 2; i -= 2) {
		cntnum[i] += cntnum[i + 2];
	}
	for (int i = rallenS - 3; i >= 2; i -= 2) {
		cntnum[i] += cntnum[i + 2];
	}
	for (int i = rallenS - 1; i >= 1; i--) {
		cntnum[i] += cntnum[i + 1];
	}
	long long ans = 0;
	for (int i = 1; i < lenT; i++) {
		if (radiusT[i] == i + 1) {
			ans += cntnum[i + 1];
		}
	}
	printf("%lld\n", ans);
	//system("pause");
	return 0;
}

