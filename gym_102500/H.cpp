#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5;
const  double eps = 1e-8;

struct node{
	double fi;
	int se;
}mx[maxn + 11],mn[maxn + 11];
double kk[maxn + 11],k[maxn + 11],b[maxn + 11],h[maxn + 11];
double g,ans;
int n,m;

int sgn(double d) {
	if (fabs(d) < eps)
		return 0;
	if (d > 0)
		return 1;
	return -1;
}

node min(node a,node b) {
	if (sgn(a.fi - b.fi) == 0) return a.se < b.se ? a : b;
	return sgn(a.fi - b.fi) == 1 ? b : a;
}

node max(node a,node b) {
	if (sgn(a.fi - b.fi) == 0) return a.se > b.se ? a : b;
	return sgn(a.fi - b.fi) == 1 ? a : b;
}

int main(){
	scanf("%d %d",&n,&m);
	for (int i = 0; i <= n; i++) { scanf("%lf",&h[i]); h[i] /= 1000; }
	for (int i = 1; i <= n; i++) {
		kk[i] = h[i] - h[i - 1];
		b[i] = h[i] - kk[i] * i;
	} 
	while (m--) {
		scanf("%lf" , &g); g -= eps;
		g /= 100;
		for (int i = 1; i <= n; i++) {
			k[i] = kk[i] - g; h[i] = k[i] * i + b[i];
			mx[i] = {h[i] , i}; mn[i] = {h[i] , i};
		}
		mx[0] = mn[0] = {h[0] , 0};
		for (int i = 1; i <= n; i++) mn[i] = min(mn[i] , mn[i - 1]);
		for (int i = n - 1; i >= 0; i--) mx[i] = max(mx[i] , mx[i + 1]);
		ans = -1;
		for (int i = 0; i < n; i++) {
			int l = i; int r = n; int rig = -1;
			while (l <= r) { 
				int mid = (l + r) >> 1;
				if (mx[mid].fi >= h[i]) { rig = mx[mid].se; l = mid + 1; } else r = mid - 1;
			} 
			if (rig == -1 || rig == i) continue;
			if (rig == n) ans = max(ans , 1.0 * rig - i);
			else ans = max(ans , (h[i] - b[rig + 1]) / k[rig + 1] - i);
		}
		for (int i = n; i >= 2; i--) {
			int l = 0; int r = i; int lef = -1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (mn[mid].fi <= h[i]) { lef = mn[mid].se; r = mid - 1; } else l = mid + 1;
			} 
			if (lef == -1 || lef == i) continue;
			if (lef == 0) ans = max(ans , 1.0 * i);
			else ans = max(ans , i - (h[i] - b[lef]) / k[lef]);
		} 
		if (ans == -1) printf("-1\n"); else printf("%.8f\n" , ans);
	} 
	return 0;
} 

