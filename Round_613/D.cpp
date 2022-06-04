#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1e5;
const int inf = (1 << 30);
int a[maxn + 11];
int cnt[35][5];
int one[35][maxn + 11],zero[35][maxn + 11];

int solve(int a[],int l,int r,int pos) {
	int val = (1 << pos);
	int l0 = cnt[pos][0] + 1;
	int l1 = cnt[pos][1] + 1;
	for (int i = l;i <= r; i++)
		if (a[i] & val) { 
			one[pos][++cnt[pos][1]] = a[i] ^ val;
		} 
		else zero[pos][++cnt[pos][0]] = a[i];
	if (pos == 0) {
		if (l0 - cnt[pos][0] == 1 || l1 - cnt[pos][1] == 1) return 0;
		return 1;
	}
	if (l0 - cnt[pos][0] == 1) return solve(one[pos] , l1 , cnt[pos][1] , pos - 1);
	if (l1 - cnt[pos][1] == 1) return solve(zero[pos] , l0 , cnt[pos][0] , pos - 1);
	return min(solve(one[pos] , l1 , cnt[pos][1] , pos - 1) , solve(zero[pos] , l0 , cnt[pos][0] , pos - 1)) + val;
} 

int main() {
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) scanf("%d" , &a[i]);
	printf("%d\n" , solve(a , 1 , n , 29));
} 

