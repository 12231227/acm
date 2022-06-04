#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mol = 1e9 + 7;
const int maxn = 1e4;

bool vis[maxn + 11][maxn + 11] = {false};
int r[maxn + 11],c[maxn + 11];

ll qpow(ll a,ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mol;
		a = a * a % mol;
		b >>= 1;
	}
	return ans;
}

int main(){
	int h,w;
	scanf("%d %d",&h,&w);
	for (int i = 1; i <= h; i++) scanf("%d",&r[i]);
	for (int i = 1; i <= w; i++) scanf("%d",&c[i]);
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= r[i]; j++)
			vis[i][j] = true;
	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= c[i]; j++)
			vis[j][i] = true;
	bool can = true;
	for (int i = 1; i <= h; i++){
		int cnt = 0;
		for (int j = 1; j <= w; j++)
			if (vis[i][j]) cnt++; else break;
		if (cnt != r[i]) can = false;
	}
	for (int i = 1; i <= w; i++){
		int cnt = 0;
		for (int j = 1; j <= h; j++)
			if (vis[j][i]) cnt++; else break;
		if (cnt != c[i]) can = false;
	}
	if (can == false) printf("0\n");
	else {
		ll cnt = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = r[i] + 2; j <= w; j++)
				if (vis[i][j] == false && i > c[j] + 1) cnt++;
		}
		printf("%lld\n" , qpow(2ll , cnt));
	}
}
