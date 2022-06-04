#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define ls k << 1
#define rs k << 1 | 1
using namespace std;

const int maxn = 1 << 21;
int a[maxn + 11];
ll ans = 0;
vector <int> v;
int h,g;

bool check(int k,int dep) {
	if (!a[ls] && !a[rs]) return dep > g;
	if (a[ls] > a[rs]) return check(ls , dep + 1);
	return check(rs , dep + 1);
}

void f(int k) {
	if (!a[ls] && !a[rs]) a[k] = 0;
	else {
		if (a[ls] > a[rs]) {
			a[k] = a[ls];
			f(ls);
		}
		else {
			a[k] = a[rs];
			f(rs);
		}
	}
}

void go(int k,int dep) {
	if (a[k] == 0) return;
	while (check(k , dep)) {
		ans -= a[k]; f(k);
		v.pb(k);
	}
	go(ls , dep + 1);
	go(rs , dep + 1);
}

int main(){
	int _;
	for (scanf("%d",&_);_;_--) {
		scanf("%d %d",&h,&g); ans = 0;
		for (int i = 1; i < (1 << h); i++) scanf("%d",&a[i]) , ans += a[i];
		v.clear();
		go(1 , 1);
		printf("%lld\n" , ans);
		for (auto x : v) printf("%d " , x); puts("");
		for (int i = 1; i < (1 << h); i++) a[i] = 0;
	}
} 

