#include <bits/stdc++.h>
using namespace std;
double ans[511];
double p[511];

double calc(int x,int n,int k) {
	double ans = k;
	for (int i = 1;i <= x; i++) ans = ans * i;
	for (int i = n - k + 1; i <= n; i++) ans = ans / i;
	for (int i = 1; i <= x - k + 1; i++) ans = ans / i;
	return ans;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i = 1; i <= n; i++) {
		scanf("%lf" , &p[i]);
		ans[i] = (double)k / n * p[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int off = j < i ? i - j : n - (j - i);
			if (n - off < k) continue;
			ans[i] += calc(n - off - 1 , n , k) * p[j];
		}
	for (int i = 1; i <= n; i++)
		printf("%.8lf%s" , ans[i] , i == n ? "\n" : " ");
} 

