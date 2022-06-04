#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

int tot = 0;
int val[maxn + 11],fa[maxn + 11];

vector <int> v;
void fac(int n) {
	v.clear();
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) { v.push_back(i); n /= i; }
		}
	}
	if (n != 1) v.push_back(n);
}

void add(int len,int f) {
	fa[++tot] = f;
	val[tot] = 1;
	for (int i = 1; i < len; i++) {
		fa[tot + 1] = tot;
		val[++tot] = 1;
	}
}

int solve(int n) {
	int now = ++tot;
	fac(n);
	if (v.size() == 1) {
		fac(--n);
	}
	else val[now]++;
	for (int i = 0; i < v.size() - 1; i++) {
		add(v[i] , now); val[now]++;
	}
	if (tot + v[v.size() - 1] > maxn) { int p = solve(v[v.size() - 1]); val[now] += val[p]; fa[p] = now; }
	else { add(v[v.size() - 1] , now); val[now]++; }
	return now;
}

int main(){
	int n;
	scanf("%d" , &n);
	if (n < maxn) {
		printf("%d\n" , n + 1);
		for (int i = 1; i <= n; i++) printf("%d%s" , i , i == n ? "\n" : " ");
		printf("2 ");
		for (int i = 2; i <= n + 1; i++) printf("1%s" , i == n + 1 ? "\n" : " ");
	}
	else {
		solve(n);
		printf("%d\n" , tot);
		for (int i = 2; i <= tot; i++) printf("%d%s" , fa[i] , i == tot ? "\n" : " ");
		for (int i = 1; i <= tot; i++) printf("%d%s" , val[i] , i == tot ? "\n" : " ");
	}
} 

