#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 100000;
int ans[maxn + 11],l[maxn + 11];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	ll sum = 0; bool flag = true;
	for (int i = 1; i <= m; i++) {
		scanf("%d" , &l[i]);
		sum += l[i];
		if (i + l[i] - 1 > n) flag = false;
	}
	if (sum < n || !flag) { puts("-1"); return 0; }
	sum = l[m];
	int ind = m;
	for (int i = m - 1; i >= 1; i--)
		if (sum + l[i] + i - 1 >= n) { ind = i; break; }
		else sum += l[i]; 
	sum = 0;
	for (int i = m; i > ind; i--) sum += l[i] , ans[i] = n - sum + 1;
	for (int i = 1; i <= ind; i++) ans[i] = i;
	for (int i = 1; i <= m; i++) printf("%d " , ans[i]);
} 

